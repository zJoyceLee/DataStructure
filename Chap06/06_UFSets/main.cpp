//STL
#include <vector>
#include <iostream>
//Current-Project
#include "UFSetsNode.hpp"
#include "UFSets.hpp"
//g-test
#include <gtest/gtest.h>

TEST(TestUFSetsClass, testUnionSet) {
    UFSets<int> s1({1}), s2({2}),   s3({3}),   s4({4}),   s5({5}),   s6({6}),   s7({7}),   s8({8});
    UFSets<int> s9({9}), s10({10}), s11({11}), s12({12}), s13({13}), s14({14}), s15({15}), s16({16});
    EXPECT_EQ(1,1);
    EXPECT_EQ({{1, -2},  {2, 0}}, 0);

}

int main(int argc, char * argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
