#include <iostream>
#include <vector>
#include <chrono>
#include "heat_solver.h"

const int nx = 10000; // Daha büyük bir problem boyutu
const double alpha = 0.01;
const double dt = 0.1;
const double dx = 1.0;
const int nt = 1000; // Daha fazla zaman adımı

int main() {
    std::vector<double> u(nx);

    initialize(u, nx);

    auto start = std::chrono::high_resolution_clock::now();
    solve_serial(u, nx, alpha, dt, dx, nt);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Serial Time: " << elapsed.count() << " s\n";

    initialize(u, nx);
    start = std::chrono::high_resolution_clock::now();
    solve_parallel(u, nx, alpha, dt, dx, nt);
    end = std::chrono::high_resolution_clock::now();
    elapsed = end - start;
    std::cout << "Parallel Time: " << elapsed.count() << " s\n";

    return 0;
}
