#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

// Define the angular frequency
const double omega_0 = 135.2e6; // Theoretical angular frequency 
const double n = 1.5e-4;        // Index or coefficient of weak focusing field

// Function to compute the derivatives
void derivatives(double z, double z_dot, double& dz_dt, double& dz_dot_dt) {
    dz_dt = z_dot;
    dz_dot_dt = -n * omega_0 * omega_0 * z;
}

// Runge-Kutta 4th Order (RK4) function to solve the equation
void RK4(double& z, double& z_dot, double dt) {
    double dz1, dz_dot1, dz2, dz_dot2, dz3, dz_dot3, dz4, dz_dot4;
    double z_temp, z_dot_temp;

    // First step
    derivatives(z, z_dot, dz1, dz_dot1);

    // Second step
    z_temp = z + 0.5 * dz1 * dt;
    z_dot_temp = z_dot + 0.5 * dz_dot1 * dt;
    derivatives(z_temp, z_dot_temp, dz2, dz_dot2);

    // Third step
    z_temp = z + 0.5 * dz2 * dt;
    z_dot_temp = z_dot + 0.5 * dz_dot2 * dt;
    derivatives(z_temp, z_dot_temp, dz3, dz_dot3);

    // Fourth step
    z_temp = z + dz3 * dt;
    z_dot_temp = z_dot + dz_dot3 * dt;
    derivatives(z_temp, z_dot_temp, dz4, dz_dot4);

    // Combine the steps
    z += (dz1 + 2 * dz2 + 2 * dz3 + dz4) * dt / 6.0;
    z_dot += (dz_dot1 + 2 * dz_dot2 + 2 * dz_dot3 + dz_dot4) * dt / 6.0;
}

int main() {
    // Initial conditions (in cm)
    double z = 5.0;       // Initial position (z(0)) in cm
    double z_dot = 0.0;   // Initial velocity (z_dot(0)) in cm/s
    double t = 0.0;       // Initial time in seconds
    double dt = 1e-9;     // Time step in seconds
    double t_final = 1e-5;  // Final time in seconds

    // File to save the results
    ofstream output("muon_VBO_trajectory_cm.txt");

    // Time integration loop
    while (t < t_final) {
        // Save the current state
        output << t << " " << z << " " << z_dot << endl;

        // Update using RK4
        RK4(z, z_dot, dt);

        // Update time
        t += dt;
    }

    output.close();
    cout << "Simulation complete. Data saved to muon_VBO_trajectory_cm.txt." << endl;

    return 0;
}

