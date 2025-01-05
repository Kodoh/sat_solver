#include "parser.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>

int num_vars = 0;
int num_clauses = 0;

CNF parseCNFFile(const std::string& filename) {
    CNF formula;
    std::ifstream file(filename);

    if (!file.is_open()) {
        throw std::runtime_error("Error: Cannot open file " + filename);
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue;

        if (line[0] == 'p') {
            std::istringstream iss(line);
            std::string tmp;
            iss >> tmp >> tmp >> num_vars >> num_clauses;
            std::cout << "Parsed problem line: num_vars = " << num_vars
                      << ", num_clauses = " << num_clauses << std::endl;
            continue;
        }

        if (line[0] == 'c') continue;

        std::istringstream iss(line);
        Clause clause;
        int literal;
        while (iss >> literal) {
            if (literal == 0) break;
            clause.push_back(literal);
        }

        formula.push_back(clause);
    }

    return formula;
}
