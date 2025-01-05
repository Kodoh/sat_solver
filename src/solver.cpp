#include "solver.h"
#include "utils.h"
#include <iostream>
#include <stdexcept>
#include <unordered_set>


Clause analyzeConflict(const Clause& conflict_clause, const Levels& levels,
    const std::unordered_map<int, Clause>& reason_clauses, int current_level) {
    Clause learned_clause = conflict_clause;
    std::unordered_set<int> seen;
    int num_current_level_literals = 0;

    for (int lit : learned_clause) {
        int var = std::abs(lit);
        if (levels[var - 1].level == current_level) {
            num_current_level_literals++;
        }
    }

    std::cout << "Starting conflict analysis with clause: ";
    printClause(conflict_clause);
    std::cout << "\n";

    while (num_current_level_literals > 1) {
        int to_resolve = -1;

        for (int lit : learned_clause) {
            int var = std::abs(lit);
            if (levels[var - 1].level == current_level) {
                to_resolve = var;
                break;
            }
        }

        if (to_resolve == -1) {
            throw std::logic_error("No literal to resolve at the current level!");
        }

        if (reason_clauses.count(to_resolve) == 0) {
            throw std::logic_error("No reason clause for variable " + std::to_string(to_resolve));
        }

        const Clause& reason_clause = reason_clauses.at(to_resolve);
        std::cout << "Resolving on variable " << to_resolve << " with reason clause: ";
        printClause(reason_clause);
        std::cout << "\n";

        learned_clause = resolveClauses(learned_clause, reason_clause, to_resolve);

        num_current_level_literals = 0;
        for (int lit : learned_clause) {
            int var = std::abs(lit);
            if (levels[var - 1].level == current_level) {
                num_current_level_literals++;
            }
        }
    }

    std::cout << "Learned clause: ";
    printClause(learned_clause);
    std::cout << "\n";

    return learned_clause;
}

// Updated backtrack with debug messages
int backtrack(const Clause& learned_clause, Levels& levels, std::stack<std::pair<int, bool>>& decisions) {
    int backtrack_level = 0;
    for (int lit : learned_clause) {
        int var = std::abs(lit);
        backtrack_level = std::max(backtrack_level, levels[var - 1].level);
    }

    std::cout << "Backtracking to level " << backtrack_level << "\n";

    while (!decisions.empty() && levels[decisions.top().first - 1].level > backtrack_level) {
        int var = decisions.top().first;
        levels[var - 1] = {0, -1};
        decisions.pop();
        std::cout << "Backtracking: Unassigning variable " << var << "\n";
    }

    return backtrack_level;
}

// Updated unitPropagate with debug messages
bool unitPropagate(CNF& formula, std::vector<int>& assignments, Levels& levels,
    std::unordered_map<int, Clause>& reason_clauses, int current_level) {
    bool updated = true;

    while (updated) {
        updated = false;

        for (auto it = formula.begin(); it != formula.end();) {
            if (it->empty()) {
                std::cout << "Conflict during unit propagation with clause: ";
                printClause(*it);
                std::cout << "\n";
                return false;
            }

            if (it->size() == 1) {
                int literal = it->front();
                int var = std::abs(literal);

                if (assignments[var - 1] == 0) {
                    assignments[var - 1] = (literal > 0) ? 1 : -1;
                    levels[var - 1] = {assignments[var - 1], current_level};
                    reason_clauses[var] = *it;

                    std::cout << "Unit propagation: Assigning x" << var << " = " 
                              << ((literal > 0) ? "True" : "False") << "\n";

                    formula = simplifyFormula(formula, assignments).first;
                    updated = true;
                    it = formula.begin();
                } else {
                    ++it;
                }
            } else {
                ++it;
            }
        }
    }

    return true;
}

// Updated dpll with debug messages
bool dpll(CNF formula, std::vector<int>& assignments) {
    Levels levels(assignments.size(), {0, -1});
    std::stack<std::pair<int, bool>> decisions;
    std::unordered_map<int, Clause> reason_clauses;

    while (true) {
        std::cout << "Starting unit propagation...\n";
        if (!unitPropagate(formula, assignments, levels, reason_clauses, decisions.size())) {
            Clause conflict_clause;
            for (const auto& clause : formula) {
                if (clause.empty()) {
                    conflict_clause = clause;
                    break;
                }
            }

            if (conflict_clause.empty()) return false;

            Clause learned_clause = analyzeConflict(conflict_clause, levels, reason_clauses, decisions.size());
            if (learned_clause.empty()) return false;

            int backtrack_level = backtrack(learned_clause, levels, decisions);
            formula.push_back(learned_clause);
            continue;
        }

        printFormula(formula);
        printAssignments(assignments);

        if (formula.empty()) {
            std::cout << "Formula is satisfied. SATISFIABLE\n";
            return true;
        }

        int variable = -1;
        for (size_t i = 0; i < levels.size(); ++i) {
            if (assignments[i] == 0) {
                variable = i + 1;
                break;
            }
        }

        if (variable == -1) {
            std::cout << "No unassigned variables. UNSATISFIABLE\n";
            return false;
        }

        std::cout << "Decision: Assigning x" << variable << " = True\n";

        decisions.push({variable, true});
        levels[variable - 1] = {1, (int)decisions.size()};
        assignments[variable - 1] = 1;
        formula = simplifyFormula(formula, assignments).first;
    }
}
