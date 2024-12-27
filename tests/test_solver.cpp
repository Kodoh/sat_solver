#include "gtest/gtest.h"
#include "../src/sat_solver.h"

TEST(SATSolverTest, BasicTest) {
        SATSolver solver;
            EXPECT_TRUE(solver.solve("data/example1.cnf"));
}

int main(int argc, char** argv) {
        ::testing::InitGoogleTest(&argc, argv);
            return RUN_ALL_TESTS();
}

