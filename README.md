# Heat Solver Project

This project provides a simple implementation of a heat equation solver in C++. The code includes both serial and parallel implementations using OpenMP.

## File Structure

- `include/`
    - Directory for header files.
- `src/`
    - Directory for source files.
- `LICENSE`
    - Project license.
- `Makefile`
    - Makefile to build the project.
- `README.md`
    - This README file.
- `devbox.json`
    - Configuration file for the development environment.
- `devbox.lock`
    - Lock file for the development environment configuration.

## Getting Started

### Prerequisites

- C++ compiler (e.g., `g++`)
- OpenMP support
- [Devbox](https://www.jetpack.io/devbox/) for managing the development environment

### Building the Project

1. Clone the repository:
    ```bash
    git clone https://github.com/omerdduran/ParallelHeatEquationSolver.git
    cd ParallelHeatEquationSolver
    ```

2. Initialize the Devbox environment:
    ```bash
    devbox shell
    ```

3. Build the project using the Makefile:
    ```bash
    make
    ```

### Without Devbox

1. Clone the repository:
    ```bash
    git clone https://github.com/omerdduran/ParallelHeatEquationSolver.git
    cd ParallelHeatEquationSolver
    ```

2. Ensure you have a C++ compiler with OpenMP support installed (e.g., `g++`).

3. Build the project using the Makefile:
    ```bash
    make
    ```
### Running the Solver

After building the project, you can run the heat solver:

```bash
./bin/heat_solver
```

### License

This project is licensed under the MIT License. See the LICENSE file for details.

### Contributing

Contributions are welcome! Please open an issue or submit a pull request.
