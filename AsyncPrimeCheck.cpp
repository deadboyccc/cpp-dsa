#include <iostream>     // For input/output operations (std::cout, std::cerr, std::cin)
#include <vector>       // For std::vector (used for the boolean sieve array)
#include <cmath>        // For std::sqrt
#include <thread>       // For std::thread to manage concurrent execution
#include <future>       // For std::async and std::future to get results from threads
#include <numeric>      // For std::iota (though not strictly used in final sieve, useful for ranges)
#include <chrono>       // For timing the execution
#include <algorithm>    // For std::min, std::max

// Function to perform the Sieve of Eratosthenes on a given segment
// This function is designed to be executed by a separate thread.
// Parameters:
//   is_prime_segment: A reference to the boolean vector representing the sieve array.
//                     This vector will be modified by the function.
//   start_index: The starting index (inclusive) of the segment to sieve.
//   end_index: The ending index (exclusive) of the segment to sieve.
//   limit: The overall upper limit for prime calculation (N).
//   base_primes: A constant reference to a vector of primes found up to sqrt(limit).
//                These primes are used to mark multiples in the segments.
void sieveSegment(std::vector<char>& is_prime_segment, long long start_index, long long end_index, long long limit, const std::vector<long long>& base_primes) {
    // Adjust segment indices to be within the valid range of the main sieve array
    // This is crucial if start_index is less than 2, or if end_index exceeds limit.
    start_index = std::max(2LL, start_index);
    end_index = std::min(limit + 1, end_index);

    // If the segment is invalid (e.g., start >= end), return
    if (start_index >= end_index) {
        return;
    }

    // Mark 0 and 1 as not prime if they fall within the segment
    if (start_index <= 0 && end_index > 0) {
        is_prime_segment[0] = 0; // Using char (0 for false, 1 for true)
    }
    if (start_index <= 1 && end_index > 1) {
        is_prime_segment[1] = 0; // Using char
    }

    // Iterate through the base primes (primes up to sqrt(limit))
    for (long long p : base_primes) {
        // If p*p overflows long long, handle it. For N = 10^7, sqrt(N) ~ 3162, p*p will not overflow.
        // For larger N, this check would be necessary.
        if (p * p > limit) {
            break; // Primes larger than sqrt(limit) don't need to sieve beyond themselves
        }

        // Calculate the first multiple of 'p' that is within the current segment and >= p*p
        // Multiples smaller than p*p would have already been marked by smaller primes.
        long long start_multiple = std::max(p * p, ((start_index + p - 1) / p) * p);

        // Mark multiples of 'p' within the segment as composite
        for (long long i = start_multiple; i < end_index; i += p) {
            is_prime_segment[i] = 0; // Mark as not prime
        }
    }
}

// Main function to calculate primes up to a given limit concurrently
long long calculatePrimes(long long limit) {
    if (limit < 2) {
        return 0; // No primes less than 2
    }

    // Use std::vector<char> instead of std::vector<bool> for potentially better
    // memory layout and to avoid `std::vector<bool>`'s specialization issues with multithreading.
    // Each char will represent a boolean (0 for false, 1 for true).
    std::vector<char> is_prime(limit + 1, 1); // Initialize all numbers as potentially prime (1 = true)
    is_prime[0] = 0; // 0 is not prime
    is_prime[1] = 0; // 1 is not prime

    // --- Step 1: Initial Sieve for base primes up to sqrt(limit) ---
    // These primes will be used by worker threads to sieve their segments.
    long long sqrt_limit = static_cast<long long>(std::sqrt(limit));
    std::vector<long long> base_primes; // Stores primes found in the initial sieve

    // Perform a sequential sieve up to sqrt_limit
    for (long long p = 2; p * p <= sqrt_limit; ++p) {
        if (is_prime[p]) { // If p is prime
            for (long long i = p * p; i <= sqrt_limit; i += p) {
                is_prime[i] = 0; // Mark multiples as not prime
            }
        }
    }

    // Collect base primes up to sqrt_limit (those that are still marked true)
    for (long long p = 2; p <= sqrt_limit; ++p) {
        if (is_prime[p]) {
            base_primes.push_back(p);
        }
    }

    // --- Step 2: Parallel Segmented Sieving ---
    unsigned int num_threads = std::thread::hardware_concurrency(); // Get recommended number of threads
    if (num_threads == 0) {
        num_threads = 4; // Fallback if hardware_concurrency returns 0
    }
    std::cout << "Using " << num_threads << " threads for prime calculation." << std::endl;

    std::vector<std::future<void>> futures; // To hold the futures of our asynchronous tasks
    long long segment_size = (limit / num_threads); // Approximate size of each segment

    // Launch threads for each segment
    for (unsigned int i = 0; i < num_threads; ++i) {
        long long start = i * segment_size;
        long long end = (i == num_threads - 1) ? (limit + 1) : (i + 1) * segment_size;

        // Ensure segments start from at least 2 if they include 0 or 1.
        // The sieveSegment function handles this adjustment internally.
        // std::async is used here to run sieveSegment asynchronously.
        // std::ref is used to pass the vector<char> by reference, allowing modification.
        futures.push_back(std::async(std::launch::async, sieveSegment, std::ref(is_prime), start, end, limit, std::cref(base_primes)));
    }

    // Wait for all threads to complete
    for (auto& f : futures) {
        f.get(); // Blocks until the associated task is complete
    }

    // --- Step 3: Count the primes ---
    long long prime_count = 0;
    for (long long i = 2; i <= limit; ++i) {
        if (is_prime[i]) {
            prime_count++;
        }
    }

    return prime_count;
}

// Main entry point of the C++ program
int main() {
    std::cout << "C++ Asynchronous Prime Number Calculator" << std::endl;
    long long limit = 10000000; // The specified limit: 10 million

    // Record the start time
    auto start_time = std::chrono::high_resolution_clock::now();

    // Calculate primes
    long long count = calculatePrimes(limit);

    // Record the end time
    auto end_time = std::chrono::high_resolution_clock::now();
    // Calculate the duration in milliseconds
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);

    // Print the results
    std::cout << "\n--------------------------------------------" << std::endl;
    std::cout << "Calculation Complete." << std::endl;
    std::cout << "Number of primes up to " << limit << ": " << count << std::endl;
    std::cout << "Time taken: " << duration.count() << " milliseconds" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;

    return 0; // Indicate successful execution
}