//STL
#include <iostream>
#include <vector>
//Current Project
#include "BinaryTree.hpp"
//g-test
#include <gtest/gtest.h>

TEST(TestBinaryTree, TestCountBrother) {
    //tree: a(bc(fg(h(ijk)))de)
	std::vector<char> pre0 = {'a', 'b', 'c', 'f', 'g', 'h', 'i', 'j', 'k', 'd', 'e'};
    std::vector<char>  in0 = {'b', 'f', 'i', 'j', 'k', 'h', 'g', 'c', 'd', 'e', 'a'};
	BinaryTree<char> bt0 = CreateBinaryTree(pre0, in0, pre0.size());
    //assert:post = {'k', 'j', 'i', 'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a'}
    EXPECT_EQ(4, bt0.countBrothers(in0));

    //tree: 1(2(3(4)))
    std::vector<int> pre1 = {1, 2, 3, 4};
    std::vector<int>  in1 = {4, 3, 2, 1};
    BinaryTree<int> bt1 = CreateBinaryTree(pre1, in1, pre1.size());
    //post = {4, 3, 2, 1}
    EXPECT_EQ(1, bt1.countBrothers(in1));

    //tree: 1(23456)
    std::vector<int> pre2 = {1, 2, 3, 4, 5, 6};
    std::vector<int>  in2 = {2, 3, 4, 5, 6, 1};
    BinaryTree<int> bt2 = CreateBinaryTree(pre2, in2, pre2.size());
    //post = {6, 5, 4, 3, 2, 1}
    EXPECT_EQ(5, bt2.countBrothers(in2));

    //woods:: tree:1(2(4)5(8)9), tree:3, tree:6, tree:7
    std::vector<int> pre3 = {1, 2, 4, 5, 8, 9, 3, 6, 7};
    std::vector<int>  in3 = {4, 8, 9, 5, 2, 1, 3, 6, 7};
    BinaryTree<int> bt3 = CreateBinaryTree(pre3, in3, pre3.size());
    //post = {4, 8, 9, 5, 2, 7, 6, 3, 1}
    EXPECT_EQ(3, bt3.countBrothers(in3));

}

int main(int argc, char * argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

