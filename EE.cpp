#include <iostream>

// sum as a function of m and B || a[n] = inserted manually
double calculateSummation(int m) {
  // starting sum
  double B, sum = 0.0;
  // input B
  std::cout << "Enter the value of B: ";
  std::cin >> B;

  // input A[n] and calculate sum
  for (int n = 1; n <= m; ++n) {
    double A_n;
    std::cout << "Enter A[" << n << "]: ";
    std::cin >> A_n;
    sum += 0.92 * A_n * B;
  }
  return sum;
}

int main() {
  // init (taking m)
  int m;
  std::cout << "Enter number of terms (m): ";
  std::cin >> m;
  // validating if m is negative or 0 = invalid
  if (m <= 0) {
    std::cout << "Invalid input. m must be greater than 0.\n";
    return 1;
  }

  double result = calculateSummation(m);
  std::cout << "Summation result: " << result << "\n";

  return 0;
}
