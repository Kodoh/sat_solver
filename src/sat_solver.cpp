#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <stdexcept>

using Clause = std::vector<int>;  // A clause is a disjunction of literals
using CNF = std::vector<Clause>; // A CNF formula is a conjunction of clauses
int num_vars;


// Function to parse a CNF file in DIMACS format
CNF parseCNFFile(const std::string& filename) {
    CNF formula;
    std::ifstream file(filename);

    if (!file.is_open()) {
        throw std::runtime_error("Error: Cannot open file " + filename);
    }

    std::string line;
    while (std::getline(file, line)) {
        // Skip comments and problem line (starts with 'c' or 'p')
        if (line.empty() || line[0] == 'c' || line[0] == 'p') {
            continue;
        }

        std::istringstream iss(line);
        Clause clause;
        int literal;

        // Read literals in the clause
        while (iss >> literal) {
            if (literal == 0) {
                break; // End of clause
            }
            num_vars = std::max(num_vars,abs(literal));
            clause.push_back(literal);
        }

        formula.push_back(clause);
    }

    return formula;
}

bool dpll(const CNF& formula) {
    std::vector<int> assignments(num_vars, 0); // Assign 0's by default meaning unassigned

    // Where formula empty -> return 1 (Satisfiable)
    if (formula.empty()) {
        return 1;
    }
    // If a clause is empty then return 0
    for (const auto& clause : formula) {
        if (clause.empty()) {
            return 0;
        }
        // Unit prop
        int negLits = 0; // number of ¬X
        int nonNegLit; // X where non negated
        for (int literal : clause) {
            if (literal < 0) {
                negLits++;
            }
            if (literal > 0) {
                nonNegLit = literal;
            }
        }
        if ((clause.size() - negLits) == 1) {
            assignments[nonNegLit] = 1;
        }
    }



    return false;
}


// Function to print the CNF formula (for debugging purposes)
void printCNF(const CNF& formula) {
    std::cout << "CNF Formula:" << std::endl;
    for (const auto& clause : formula) {
        for (int literal : clause) {
            std::cout << literal << " ";
        }
        std::cout << "0" << std::endl; // End each clause with '0' like DIMACS format
    }
}

int main(int argc, char** argv) {
    // Ensure the user provides a CNF file as an argument
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <cnf_file>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];

    try {
        // Parse the CNF file
        CNF formula = parseCNFFile(filename);

        // Print the formula (optional, for verification)
        printCNF(formula);
        

        std::cout << num_vars << std::endl;

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
