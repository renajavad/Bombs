#include "detonatedBombs.cpp"
#include <gtest/gtest.h>
#include <vector>
TEST(MaxBombs, DetonatedTest)
{
    std::vector<std::vector<int>> bombs1 = {{2, 1, 3}, {6, 1, 4}};
    
    std::vector<std::vector<int>> bombs2 = {{1, 2, 3}, {2, 3, 1}, {3, 4, 2}, {4, 5, 3}, {5, 6, 4}};

    std::vector<std::vector<int>> bombs3 = {{1, 1, 5}, {10, 10, 5}};

	ASSERT_EQ (2,maxDetonatedBombs(bombs1));
	ASSERT_EQ (5,maxDetonatedBombs(bombs2));
	ASSERT_EQ (1,maxDetonatedBombs(bombs3));
}
int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
