#include <iostream>
#include "sat_solver.h"

int main() {

    std::string cnf_file = "data/example1.cnf";
        SATSolver solver;
            if (solver.solve(cnf_file)) {
                        std::cout << "SATISFIABLE" << std::endl;
                            } else {
                                        std::cout << "UNSATISFIABLE" << std::endl;
                                            }
                return 0;
}
