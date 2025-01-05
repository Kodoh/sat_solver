#ifndef SOLVER_H
#define SOLVER_H

#include "parser.h"
#include <stack>
#include <unordered_map>

// Structs
struct VariableInfo {
    int assignment;
    int level;
};

using Levels = std::vector<VariableInfo>;

// Functions
bool dpll(CNF formula, std::vector<int>& assignments);
Clause analyzeConflict(const Clause& conflict_clause, const Levels& levels, const std::unordered_map<int, Clause>& reason_clauses, int current_level);
int backtrack(const Clause& learned_clause, Levels& levels, std::stack<std::pair<int, bool>>& decisions);

#endif // SOLVER_H
