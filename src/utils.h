#ifndef UTILS_H
#define UTILS_H

#include "parser.h"
#include <unordered_map>

// Functions
void printFormula(const CNF& formula);
std::pair<CNF, Clause> simplifyFormula(const CNF& formula, const std::vector<int>& assignments);
Clause resolveClauses(const Clause& clause1, const Clause& clause2, int var);
void printAssignments(const std::vector<int>& assignments);
void printClause(const Clause& clause);

#endif // UTILS_H
