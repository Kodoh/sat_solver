#include "utils.h"
#include <iostream>
#include <unordered_map>
#include <unordered_set>

void printFormula(const CNF& formula) {
    std::cout << "Current formula:" << std::endl;
    for (const auto& clause : formula) {
        std::cout << "(";
        for (size_t i = 0; i < clause.size(); ++i) {
            int literal = clause[i];
            if (literal < 0) {
                std::cout << "¬" << -literal; // Use '¬' for negation
            } else {
                std::cout << literal;
            }
            if (i != clause.size() - 1) {
                std::cout << " ∨ ";
            }
        }
        std::cout << ")" << std::endl;
    }
    std::cout << "--------------------------------" << std::endl;
}

void printClause(const Clause& clause) {
    std::cout << "{ ";
    for (int lit : clause) {
        std::cout << lit << " ";
    }
    std::cout << "}";
}

Clause resolveClauses(const Clause& clause1, const Clause& clause2, int var) {
    Clause resolved_clause;
    std::unordered_set<int> literals;

    for (int literal : clause1) {
        if (literal != var && literal != -var) literals.insert(literal);
    }

    for (int literal : clause2) {
        if (literal != var && literal != -var) literals.insert(literal);
    }

    for (int literal : literals) {
        resolved_clause.push_back(literal);
    }

    return resolved_clause;
}

void printAssignments(const std::vector<int>& assignments) {
    std::cout << "Assignments: ";
    for (size_t i = 0; i < assignments.size(); ++i) {
        std::cout << "x" << (i + 1) << "=";
        if (assignments[i] == 1)
            std::cout << "True ";
        else if (assignments[i] == -1)
            std::cout << "False ";
        else
            std::cout << "Unassigned ";
    }
    std::cout << "\n";
}

std::pair<CNF, Clause> simplifyFormula(const CNF& formula, const std::vector<int>& assignments) {
    CNF simplified;
    Clause conflict_clause;

    for (const auto& clause : formula) {
        Clause new_clause;
        bool satisfied = false;

        for (int literal : clause) {
            int var = std::abs(literal);
            int value = assignments[var - 1]; // Access assignment for variable

            if (value != 0) { // Check if variable is assigned
                if ((literal > 0 && value == 1) || (literal < 0 && value == -1)) {
                    satisfied = true; // Clause is satisfied
                    break;
                }
            } else {
                new_clause.push_back(literal); // Keep unassigned literals
            }
        }

        if (!satisfied) {
            if (new_clause.empty()) {
                conflict_clause = clause; // Preserve the original conflicting clause
            } else {
                simplified.push_back(new_clause);
            }
        }
    }

    return {simplified, conflict_clause};
}
