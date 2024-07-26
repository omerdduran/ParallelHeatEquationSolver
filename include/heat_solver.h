#ifndef HEAT_SOLVER_H
#define HEAT_SOLVER_H

#include <vector> // Required for using the vector data structure

// Function to initialize the heat vector
void initialize(std::vector<double>& u, int nx);

// Function to solve the heat equation serially
void solve_serial(std::vector<double>& u, int nx, double alpha, double dt, double dx, int nt);

// Function to solve the heat equation in parallel
void solve_parallel(std::vector<double>& u, int nx, double alpha, double dt, double dx, int nt);

#endif // HEAT_SOLVER_H
