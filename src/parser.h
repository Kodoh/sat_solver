#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <string>

// Define types for readability
using Clause = std::vector<int>;
using CNF = std::vector<Clause>;

extern int num_vars;
extern int num_clauses;

// Functions
CNF parseCNFFile(const std::string& filename);

#endif // PARSER_H
