#include <gtest/gtest.h>
#include "../matrix_multiplication.h"

using namespace std;

/*
 | 1 2 3 |   | 1 0 0 |     | 14 2 3 |
 | 0 1 0 | x | 2 1 0 |  =  |  2 1 0 |
 | 0 0 1 |   | 3 0 1 |     |  3 0 1 |
*/
TEST(Multiplication, SimpleAlgorithm) {
    matrix_t m1 = {{1, 2, 3},
                   {0, 1, 0},
                   {0, 0, 1}};
    matrix_t m2 = {{1, 0, 0},
                   {2, 1, 0},
                   {3, 0, 1}};
    matrix_t ans = {{14, 2, 3},
                    {2,  1, 0},
                    {3,  0, 1}};
    ASSERT_EQ(ans, simple_multiply(m1, m2));
}

TEST(Multiplication, BlockAlgorithm) {
    matrix_t m1 = get_random_matrix(300, 300);
    matrix_t m2 = get_random_matrix(300, 300);
    ASSERT_EQ(simple_multiply(m1, m2), block_multiply(m1, m2, 2));
    ASSERT_EQ(simple_multiply(m1, m2), block_multiply(m1, m2, 5));
    ASSERT_EQ(simple_multiply(m1, m2), block_multiply(m1, m2, 10));
    ASSERT_EQ(simple_multiply(m1, m2), block_multiply(m1, m2, 100));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
