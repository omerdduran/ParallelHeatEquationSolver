#include <iostream>
#include <vector>        // Required for using the vector data structure
#include <chrono>        // Required for measuring time
#include "heat_solver.h" // Header file for heat solution functions

const int nx = 1000000;       // Number of grid points
const double alpha = 0.01;  // Thermal diffusivity
const double dt = 0.1;      // Time step
const double dx = 1.0;      // Grid spacing
const int nt = 1000;        // Number of time steps

int main() {
    std::vector<double> u(nx);  // Vector to hold heat values

    initialize(u, nx);  // Initialize the heat vector

    // Measure the time for the serial solution
    auto start = std::chrono::high_resolution_clock::now();
    solve_serial(u, nx, alpha, dt, dx, nt);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Serial Time: " << elapsed.count() << " s\n";

    initialize(u, nx);  // Reinitialize the heat vector

    // Measure the time for the parallel solution
    start = std::chrono::high_resolution_clock::now();
    solve_parallel(u, nx, alpha, dt, dx, nt);
    end = std::chrono::high_resolution_clock::now();
    elapsed = end - start;
    std::cout << "Parallel Time: " << elapsed.count() << " s\n";

    return 0;  // End the program
}
