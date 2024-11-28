#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

// Define the angular frequency
const double omega_0 = 135.2e6; // Theoretical angular frequency
const double n = 1.5e-4;        // Index

// Function to compute the derivatives
void derivatives(double x, double x_dot, double& dx_dt, double& dx_dot_dt) {
    dx_dt = x_dot;
    dx_dot_dt = -(1 - n) * omega_0 * omega_0 * x;
}

// Runge-Kutta 4th Order (RK4) function to solve the equation
void RK4(double& x, double& x_dot, double dt) {
    double dx1, dx_dot1, dx2, dx_dot2, dx3, dx_dot3, dx4, dx_dot4;
    double x_temp, x_dot_temp;

    // First step
    derivatives(x, x_dot, dx1, dx_dot1);

    // Second step
    x_temp = x + 0.5 * dx1 * dt;
    x_dot_temp = x_dot + 0.5 * dx_dot1 * dt;
    derivatives(x_temp, x_dot_temp, dx2, dx_dot2);

    // Third step
    x_temp = x + 0.5 * dx2 * dt;
    x_dot_temp = x_dot + 0.5 * dx_dot2 * dt;
    derivatives(x_temp, x_dot_temp, dx3, dx_dot3);

    // Fourth step
    x_temp = x + dx3 * dt;
    x_dot_temp = x_dot + dx_dot3 * dt;
    derivatives(x_temp, x_dot_temp, dx4, dx_dot4);

    // Combine the steps
    x += (dx1 + 2 * dx2 + 2 * dx3 + dx4) * dt / 6.0;
    x_dot += (dx_dot1 + 2 * dx_dot2 + 2 * dx_dot3 + dx_dot4) * dt / 6.0;
}

int main() {
    // Initial conditions (in cm)
    double x = 1.0;      // Initial position (x(0)) in cm
    double x_dot = 0.0;    // Initial velocity (x_dot(0)) in cm/s
    double t = 0.0;        // Initial time in seconds
    double dt = 1e-9;      // Time step in seconds
    double t_final = 120e-9; // Final time in seconds

    // File to save the results
    ofstream output("horizontal_betatron_oscillation_cm.txt");

    // Time integration loop
    while (t < t_final) {
        // Save the current state
        output << t << " " << x << " " << x_dot << endl;

        // Update using RK4
        RK4(x, x_dot, dt);

        // Update time
        t += dt;
    }

    output.close();
    cout << "Simulation complete. Data saved to horizontal_betatron_oscillation_cm.txt." << endl;

    return 0;
}

