#include <iostream>
#include <vector>
#include "parser.h"
#include "utils.h"
#include "solver.h"

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <cnf_file>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];

    try {
        CNF formula = parseCNFFile(filename);
        std::vector<int> assignments(num_vars, 0);

        printFormula(formula); // Print the initial formula

        bool result = dpll(formula, assignments);
        if (result) {
            std::cout << "SATISFIABLE" << std::endl;
        } else {
            std::cout << "UNSATISFIABLE" << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
