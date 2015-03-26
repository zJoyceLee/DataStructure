//STL
#include <vector>
#include <iostream>
//Current-Project
#include "UFSetsNode.hpp"
#include "UFSets.hpp"
// Current-Test
#include "helper.hpp"
//g-test
#include <gtest/gtest.h>

TEST(TestUFSetsClass, testUnionSet) {
    UFSets<int> s1({1}), s2({2}),   s3({3}),   s4({4}),   s5({5}),   s6({6}),   s7({7}),   s8({8});
    UFSets<int> s9({9}), s10({10}), s11({11}), s12({12}), s13({13}), s14({14}), s15({15}), s16({16});
    std::vector<UFSets<int>> allSets = {s1,s2,s3,s4,s5,s6,s7,s8,s9,s10,s11,s12,s13,s14,s15,s16};

    s1.unionSet(s2);
    assert_eq_UFSets_vector({{1,-2} , {2,0}} , s1);

    s3.unionSet(s4);
    assert_eq_UFSets_vector({{3,-2},{4,0}}, s3);

    s3.unionSet(s5);
    assert_eq_UFSets_vector({{3,-3},{4,0},{5,0}},s3);

    s1.unionSet(s7);
    assert_eq_UFSets_vector({{1,-3},{2,0},{7,0}},s1);

    s3.unionSet(s6);
    assert_eq_UFSets_vector({{3,-4},{4,0},{5,0},{6,0}},s3);

    s8.unionSet(s9);
    assert_eq_UFSets_vector({{8,-2},{9,0}},s8);

    s1.unionSet(s8);
    assert_eq_UFSets_vector({{1,-5},{2,0},{7,0},{8,0},{9,3}},s1);

    s3.unionSet(s10);
    assert_eq_UFSets_vector({{3,-5},{4,0},{5,0},{6,0},{10,0}},s3);

    s3.unionSet(s11);
    assert_eq_UFSets_vector({{3,-6},{4,0},{5,0},{6,0},{10,0},{11,0}},s3);

    s3.unionSet(s12);
    assert_eq_UFSets_vector({{3,-7},{4,0},{5,0},{6,0},{10,0},{11,0},{12,0}},s3);

    s3.unionSet(s13);
    assert_eq_UFSets_vector({{3,-8},{4,0},{5,0},{6,0},{10,0},{11,0},{12,0},{13,0}},s3);

    s14.unionSet(s15);
    assert_eq_UFSets_vector({{14,-2},{15,0}},s14);

    UFSets<int> s0({0});
    s16.unionSet(s0);
    assert_eq_UFSets_vector({{16,-2},{0,0}},s16);

    s14.unionSet(s16);
    assert_eq_UFSets_vector({{14,-4},{15,0},{16,0},{0,2}},s14);

    s1.unionSetByNodeNum(s3);
    assert_eq_UFSets_vector({{3,-13},{4,0},{5,0},{6,0},{10,0},{11,0},{12,0},{13,0},{1,0},{2,8},{7,8},{8,8},{9,11}},s1);

    EXPECT_EQ(1,1);

    assert_eq_vector(std::vector<UFSetsNode<int>>({{1,-2}, {2,0}}), *(UFSets<int>({1, 2}).data()));
    assert_eq_UFSets_vector({{1,-2} , {2,0}} , UFSets<int>({1 , 2 }));


}

int main(int argc, char * argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
