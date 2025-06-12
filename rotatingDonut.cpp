#include <iostream>  // For input/output operations (cout, cerr)
#include <vector>    // For dynamic arrays (std::vector)
#include <cmath>     // For mathematical functions (sin, cos, M_PI)
#include <string>    // For string manipulation
#include <chrono>    // For time-related functions (sleep_for)
#include <thread>    // For thread operations (this_thread::sleep_for)
#include <cstdlib>   // For system calls (system) - used for clearing screen
#include <algorithm> // For std::max and std::min

// --- Donut Parameters ---
// R1: The radius of the torus tube (the 'thickness' of the donut).
const float R1 = 1.0f;
// R2: The distance from the center of the donut's hole to the center of its tube (the 'major radius').
const float R2 = 2.0f;

// --- Screen & Projection Parameters ---
// Adjust SCREEN_WIDTH and SCREEN_HEIGHT to best fit your terminal window size.
// A wider terminal allows for a larger or wider donut.
const int SCREEN_WIDTH = 80;
const int SCREEN_HEIGHT = 22; // Using a slightly smaller height than common 24 to avoid scroll issues on some terminals.

// K_PROJECTION: A scaling factor that determines the visual size of the donut on the screen.
// Increase this value to make the donut appear larger; decrease it to make it smaller.
const float K_PROJECTION = 40.0f; // A good starting value for an 80x22 terminal.

// K_DEPTH: Represents the simulated distance from the viewer to the center of the donut.
// Higher values make the donut appear further away, affecting perspective.
// Calculated as R1 + R2 (the closest point on the donut to the origin) plus an offset.
const float K_DEPTH = R1 + R2 + 5.0f;

// CHARACTERS: A string of characters used for shading, ordered from darkest/least dense
// to brightest/most dense. The more characters, the finer the shading gradient.
// This sequence gives a good visual progression from empty space to solid.
const std::string CHARACTERS = " .',:;c!jJt+*sSaA#@$%"; // A set of 20 characters for detailed shading.

// --- Rotation Angles ---
// A: Current rotation angle (in radians) around the X-axis.
// B: Current rotation angle (in radians) around the Z-axis (as in the classic implementation
//    which simulates a top-down rotation).
static float A = 0.0f;
static float B = 0.0f;

// --- Animation Loop Function ---
void animateDonut() {
    // Initialize buffers for the current frame to store screen state.
    // output_buffer: A 1D vector representing the 2D terminal screen. Each element stores
    //                the ASCII character to be displayed at that pixel.
    std::vector<char> output_buffer(SCREEN_WIDTH * SCREEN_HEIGHT, ' ');
    // z_buffer: A 1D vector (depth buffer) storing the inverse depth (1/z) for each pixel.
    //           Used for hidden surface removal: only draw a point if it's closer to the
    //           viewer than any other point already rendered at that screen location.
    std::vector<float> z_buffer(SCREEN_WIDTH * SCREEN_HEIGHT, 0.0f);

    // Pre-calculate sine and cosine values for the current rotation angles A and B.
    // Doing this once per frame is more efficient than repeatedly calculating inside loops.
    float cosA = std::cos(A);
    float sinA = std::sin(A);
    float cosB = std::cos(B);
    float sinB = std::sin(B);

    // Iterate through 'theta' and 'phi' to generate points across the torus surface.
    // The torus is parameterized by these two angles:
    //   - theta: Angle around the torus tube (minor circle, 0 to 2*pi).
    //            Controls the 'vertical' position on the tube's cross-section.
    //   - phi:   Angle around the main circle of the donut (major circle, 0 to 2*pi).
    //            Controls the 'horizontal' position around the donut's circumference.
    const float THETA_INCREMENT = 0.07f; // Step size for theta. Smaller value = more vertical points, smoother donut.
    const float PHI_INCREMENT = 0.02f;   // Step size for phi. Smaller value = more horizontal points, smoother donut.

    for (float theta = 0.0f; theta < 2 * M_PI; theta += THETA_INCREMENT) {
        float cos_theta = std::cos(theta);
        float sin_theta = std::sin(theta);

        // Calculate base coordinates (x, y) for a point on the torus before full 3D rotation.
        // These are the local coordinates within the torus's own reference frame.
        float circ_x = R2 + R1 * cos_theta; // Distance from origin to the center of the tube's cross-section
        float circ_y = R1 * sin_theta;      // Height relative to the major plane of the donut

        for (float phi = 0.0f; phi < 2 * M_PI; phi += PHI_INCREMENT) {
            float cos_phi = std::cos(phi);
            float sin_phi = std::sin(phi);

            // --- 3D Rotation and Translation ---
            // These formulas transform the 3D point from the donut's local coordinates
            // to screen-space 3D coordinates, applying the A and B rotations and
            // translating the donut by K_DEPTH away from the viewer.
            float x_prime = circ_x * (cosB * cos_phi + sinA * sinB * sin_phi) - circ_y * cosA * sinB;
            float y_prime = circ_x * (sinB * cos_phi - sinA * cosB * sin_phi) + circ_y * cosA * cosB;
            float z_prime = K_DEPTH + cos_phi * circ_x * sinA + sin_theta * R1 * cosA;

            // --- Luminance (Shading) Calculation ---
            // L represents the light intensity at the current point on the torus surface.
            // It's calculated based on the dot product of the surface normal (direction the surface faces)
            // and an implicit light source vector (assumed to be coming directly from the viewer's eye).
            float L = cos_phi * cos_theta * sinB - cos_theta * sinA * sin_phi - sin_theta * cosA;

            // --- Perspective Projection to 2D Screen ---
            // ooz (one over z_prime) is crucial for perspective projection and depth buffering.
            // Points further away (larger z_prime) will have a smaller ooz, making them appear smaller
            // and effectively giving the illusion of depth.
            float ooz = 1.0f / z_prime;

            // Calculate the 2D screen coordinates (pixel position) where this 3D point projects.
            // SCREEN_WIDTH/2 and SCREEN_HEIGHT/2 center the donut on the screen.
            // K_PROJECTION scales the donut to fit the screen.
            int proj_x = static_cast<int>(SCREEN_WIDTH / 2 + K_PROJECTION * x_prime * ooz);
            int proj_y = static_cast<int>(SCREEN_HEIGHT / 2 + K_PROJECTION * y_prime * ooz);

            // --- Depth Buffering and Character Assignment ---
            // Check if the projected point falls within the visible screen area.
            if (proj_x >= 0 && proj_x < SCREEN_WIDTH && proj_y >= 0 && proj_y < SCREEN_HEIGHT) {
                // Calculate the 1D array index corresponding to the 2D screen pixel.
                int idx = proj_x + SCREEN_WIDTH * proj_y;

                // If the current point is closer to the viewer than any point previously
                // rendered at this specific pixel, then update the z_buffer and output_buffer.
                if (ooz > z_buffer[idx]) {
                    z_buffer[idx] = ooz; // Update the depth buffer with the new, closer depth.
                    // Map the calculated luminance value (L) to a character from the CHARACTERS string.
                    // L typically ranges from -1 (darkest) to 1 (brightest).
                    // This formula scales L to an appropriate index (0 to len(CHARACTERS)-1).
                    int char_index = static_cast<int>((L + 1) / 2.0f * (CHARACTERS.length() - 1));
                    // Clamp the index to ensure it's within the valid range of CHARACTERS.
                    char_index = std::max(0, std::min(static_cast<int>(CHARACTERS.length() - 1), char_index));
                    output_buffer[idx] = CHARACTERS[char_index];
                }
            }
        }
    }

    // --- Render Frame to Terminal ---
    // "\x1b[H" is an ANSI escape code that moves the terminal cursor to the home position (top-left).
    // This causes the new frame to overwrite the previous one, creating a smooth animation effect.
    std::cout << "\x1b[H";
    // Print each row of the output_buffer to the terminal.
    for (int i = 0; i < SCREEN_HEIGHT; ++i) {
        for (int j = 0; j < SCREEN_WIDTH; ++j) {
            std::cout << output_buffer[i * SCREEN_WIDTH + j];
        }
        std::cout << "\n"; // Newline after each row
    }
    // Flush the output buffer to ensure immediate display.
    std::cout.flush();

    // --- Update Rotation Angles and Frame Rate Control ---
    // Increment angles A and B for the next frame to simulate continuous rotation.
    A += 0.04f;
    B += 0.02f;
    
    // Pause for a short duration to control the animation speed (frames per second).
    // 0.05 seconds pause means approximately 20 frames per second (1/0.05 = 20).
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
}

// --- Main Program Execution ---
int main() {
    // Initial setup: Clear the terminal screen and hide the cursor for cleaner animation.
    // Check OS type to use appropriate clear command.
    #ifdef _WIN32
        system("cls"); // For Windows
    #else
        system("clear"); // For Unix/Linux/macOS
    #endif

    std::cout << "\x1b[?25l"; // ANSI escape code to hide the cursor.
    std::cout.flush(); // Ensure cursor is hidden before animation starts.

    // Run the animation indefinitely until interrupted.
    // A simple loop; Ctrl+C will typically terminate the process.
    // On termination, the 'finally' part (below) will try to restore the cursor.
    while (true) {
        animateDonut();
    }

    // This part might not be reached if terminated by Ctrl+C directly,
    // but included for completeness in case of graceful exit mechanisms.
    std::cout << "\x1b[?25h"; // ANSI escape code to show the cursor.
    std::cout << "\nExiting Donut program." << std::endl;

    return 0;
}