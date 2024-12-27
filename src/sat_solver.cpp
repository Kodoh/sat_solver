#include "sat_solver.h"
#include <iostream>
#include <fstream>

bool SATSolver::solve(const std::string& cnf_file) {
        std::ifstream file(cnf_file);
            if (!file.is_open()) {
               std::cerr << "Error opening file: " << cnf_file << std::endl;
               return false;
             }
            return true;
}
