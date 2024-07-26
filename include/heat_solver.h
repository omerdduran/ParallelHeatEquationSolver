#ifndef HEAT_SOLVER_H
#define HEAT_SOLVER_H

#include <vector>

void initialize(std::vector<double>& u, int nx);
void solve_serial(std::vector<double>& u, int nx, double alpha, double dt, double dx, int nt);
void solve_parallel(std::vector<double>& u, int nx, double alpha, double dt, double dx, int nt);

#endif // HEAT_SOLVER_H
