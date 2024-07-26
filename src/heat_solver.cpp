#include "heat_solver.h" // Header file for heat solver functions
#include <omp.h>         // OpenMP library for parallelization

// Function to initialize the heat vector
void initialize(std::vector<double>& u, int nx) {
    for (int i = 0; i < nx; ++i) {
        u[i] = 0.0; // Initialize all elements to 0.0
    }
    u[nx / 2] = 100.0; // Set the middle element to 100.0
}

// Function to solve the heat equation serially
void solve_serial(std::vector<double>& u, int nx, double alpha, double dt, double dx, int nt) {
    std::vector<double> u_new(nx); // Vector to hold new values of u
    for (int n = 0; n < nt; ++n) {
        for (int i = 1; i < nx - 1; ++i) {
            // Update each element based on the heat equation
            u_new[i] = u[i] + alpha * dt / (dx * dx) * (u[i + 1] - 2 * u[i] + u[i - 1]);
        }
        u = u_new; // Update u with new values
    }
}

// Function to solve the heat equation in parallel
void solve_parallel(std::vector<double>& u, int nx, double alpha, double dt, double dx, int nt) {
    std::vector<double> u_new(nx); // Vector to hold new values of u
    for (int n = 0; n < nt; ++n) {
#pragma omp parallel for
        for (int i = 1; i < nx - 1; ++i) {
            // Update each element based on the heat equation in parallel
            u_new[i] = u[i] + alpha * dt / (dx * dx) * (u[i + 1] - 2 * u[i] + u[i - 1]);
        }
#pragma omp parallel for
        for (int i = 1; i < nx - 1; ++i) {
            u[i] = u_new[i]; // Update u with new values in parallel
        }
    }
}
