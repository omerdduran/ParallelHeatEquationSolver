#include "heat_solver.h"
#include <omp.h>

void initialize(std::vector<double>& u, int nx) {
    for (int i = 0; i < nx; ++i) {
        u[i] = 0.0;
    }
    u[nx / 2] = 100.0;
}

void solve_serial(std::vector<double>& u, int nx, double alpha, double dt, double dx, int nt) {
    std::vector<double> u_new(nx);
    for (int n = 0; n < nt; ++n) {
        for (int i = 1; i < nx - 1; ++i) {
            u_new[i] = u[i] + alpha * dt / (dx * dx) * (u[i + 1] - 2 * u[i] + u[i - 1]);
        }
        u = u_new;
    }
}

void solve_parallel(std::vector<double>& u, int nx, double alpha, double dt, double dx, int nt) {
    std::vector<double> u_new(nx);
    for (int n = 0; n < nt; ++n) {
#pragma omp parallel for
        for (int i = 1; i < nx - 1; ++i) {
            u_new[i] = u[i] + alpha * dt / (dx * dx) * (u[i + 1] - 2 * u[i] + u[i - 1]);
        }
#pragma omp parallel for
        for (int i = 1; i < nx - 1; ++i) {
            u[i] = u_new[i];
        }
    }
}
