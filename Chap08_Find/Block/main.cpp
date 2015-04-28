//STL
#include <vector>
#include <utility>
#include <string>
#include <iostream>
//C-Standard
#include <cmath>
//g_test
#include <gtest/gtest.h>
//Current Project
#include "helper.hpp"

template <typename T>
struct Block {
    T maxData;
    std::vector<T> data;
};

std::vector<int> sortToIncreasingOrder(std::vector<int> vec) {
    std::size_t k = 0, index = 0, i = 0, p = 0;
    for(k = 0; k < vec.size() -1; ++k) {
		index = k;
		for(i = k + 1; i < vec.size(); ++i)
            if(vec[i] < vec[index])
                index = i;
        p = vec[index];
        vec[index] = vec[k];
        vec[k] = p;
	}
	return vec;
}

TEST(Block, testSortToIncreasingOrder) {
    assert_eq_vector({0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, sortToIncreasingOrder({4, 5, 3, 9, 7, 8, 6, 2, 0, 1}));
    assert_eq_vector({10, 11, 24, 30}, sortToIncreasingOrder({30, 11, 10, 24}));
    assert_eq_vector({72,73,74, 88, 99}, sortToIncreasingOrder({74, 73, 72, 99, 88}));
}

template <typename T>
std::vector<T> copyVec(const std::vector<T> & myvec) {
    std::vector<T> vec;
    for(auto it = myvec.begin(); it != myvec.end(); ++it) {
        vec.push_back(*it);
    }
    return vec;
}

//int binarySearch(int target, const std::vector<int> & increasingOrderVec) {
//    std::vector<int> tmpVec = copyVec<int>(increasingOrderVec);
//
//    if(tmpVec.size() == 0)
//        return -1;
//
//    std::size_t high = tmpVec.size() - 1;
//    std::size_t mid = std::size_t(ceil(high / 2));
//
//    if(target == tmpVec[mid])
//        return int(mid);
//
//    if(target < tmpVec[mid]) {
//    //about erase: [1,2,3,4,5,6].erase(begin(), begin()+3) --> [4,5,6]
//        tmpVec.erase(tmpVec.begin() + mid, tmpVec.end());
//        return binarySearch(target, tmpVec);
//    }
//    if(target > tmpVec[mid]) {
//        tmpVec.erase(tmpVec.begin(), tmpVec.begin() + mid + 1);
//        return mid + 1 + binarySearch(target, tmpVec);
//    }
//}
//TEST(Block, testBinarySaerch) {
//    std::vector<int> num = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
//    EXPECT_EQ( 3, binarySearch(  3, num));
//    EXPECT_EQ(-1, binarySearch( 20, num));
//    EXPECT_EQ( 9, binarySearch(  9, num));
//    EXPECT_EQ( 0, binarySearch(  0, num));
//    EXPECT_EQ(-1, binarySearch(-33, num));
//
//    //------------------------------0---1---2---3---4---5---6
//    EXPECT_EQ( 0, binarySearch( 3, {3, 20, 21, 22, 30, 35, 40}));
//    EXPECT_EQ( 5, binarySearch(35, {3, 20, 21, 22, 30, 35, 40}));
//    EXPECT_EQ(-1, binarySearch( 0, {3, 20, 21, 22, 30, 35, 40}));
//    EXPECT_EQ(-1, binarySearch(90, {3, 20, 21, 22, 30, 35, 40}));
//    EXPECT_EQ(-1, binarySearch(33, {3, 20, 21, 22, 30, 35, 40}));
//}

int binarySearch(int low, int high, int target, std::vector<int> increasingOrderVec) {
    int mid = low + (high - low) / 2;
    if(low > high) {
        return -1;
    } else {
        if(increasingOrderVec[mid] == target)
            return mid;
        if(increasingOrderVec[mid] > target)
            return binarySearch(low, mid - 1, target, increasingOrderVec);
        if(increasingOrderVec[mid] < target)
            return binarySearch(mid + 1, high, target, increasingOrderVec);
    }
}

TEST(Block, testBinarySearch) {
    std::vector<int> num = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    EXPECT_EQ( 3, binarySearch(0, num.size(),  3, num));
    EXPECT_EQ(-1, binarySearch(0, 10, 20, num));
    EXPECT_EQ( 9, binarySearch(0, 10,  9, num));
    EXPECT_EQ( 0, binarySearch(0, 10,  0, num));
    EXPECT_EQ(-1, binarySearch(0, 10,-33, num));

    //------------------------------------0---1---2---3---4---5---6
    EXPECT_EQ( 0, binarySearch(0, 7,  3, {3, 20, 21, 22, 30, 35, 40}));
    EXPECT_EQ( 5, binarySearch(0, 7, 35, {3, 20, 21, 22, 30, 35, 40}));
    EXPECT_EQ(-1, binarySearch(0, 7,  0, {3, 20, 21, 22, 30, 35, 40}));
    EXPECT_EQ(-1, binarySearch(0, 7, 90, {3, 20, 21, 22, 30, 35, 40}));
    EXPECT_EQ(-1, binarySearch(0, 7, 33, {3, 20, 21, 22, 30, 35, 40}));
}

int findRange(int target, std::vector<int> increasingOrderVec) {
    int low = 0;
    int high = increasingOrderVec.size() - 1;
    int mid = 0;
    while(low <= high) {
        mid = (low + high) / 2;
        if(target == increasingOrderVec[mid])
            return mid;
        else if(target <= increasingOrderVec[mid])
            high = mid -1;
        else
            low = mid + 1;
    }
    if(low > increasingOrderVec.size() - 1)
        return -1;
    return low;
}

TEST(Block, testFindRange) {
    //---------------------------------0---1---2---3---4---5---6
    EXPECT_EQ( 0, findRange( 0, {3, 20, 21, 22, 30, 35, 40}));
    EXPECT_EQ(-1, findRange(90, {3, 20, 21, 22, 30, 35, 40}));
    EXPECT_EQ( 5, findRange(33, {3, 20, 21, 22, 30, 35, 40}));

    EXPECT_EQ( 0,findRange(  8, {10, 24, 33, 99}));
    EXPECT_EQ( 1,findRange( 22, {10, 24, 33, 99}));
    EXPECT_EQ( 2,findRange( 29, {10, 24, 33, 99}));
    EXPECT_EQ( 3,findRange( 88, {10, 24, 33, 99}));
    EXPECT_EQ(-1,findRange(100, {10, 24, 33, 99}));
}

int findByLoop(int target, const std::vector<int> & vec) {
    for(std::size_t i = 0; i < vec.size(); ++i) {
        if(vec[i] == target) {
            return i;
        }
    }
    return -1;
}

TEST(Block, testFindByLoop) {
    std::vector<int> num = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    EXPECT_EQ( 3, findByLoop(  3, num));
    EXPECT_EQ(-1, findByLoop( 20, num));
    EXPECT_EQ( 9, findByLoop(  9, num));
    EXPECT_EQ( 0, findByLoop(  0, num));
    EXPECT_EQ(-1, findByLoop(-33, num));

    //------------------------------0---1---2---3---4---5---6
    EXPECT_EQ( 0, findByLoop( 3, {3, 20, 21, 22, 30, 35, 40}));
    EXPECT_EQ( 5, findByLoop(35, {3, 20, 21, 22, 30, 35, 40}));
    EXPECT_EQ(-1, findByLoop( 0, {3, 20, 21, 22, 30, 35, 40}));
    EXPECT_EQ(-1, findByLoop(90, {3, 20, 21, 22, 30, 35, 40}));
}

std::pair<int, int> blockFind(int target, std::vector<Block<int>> myBlocks) {
    std::pair<int, int> position;
    std::vector<int> iNodeData;
    int indexInINode = -1;
    for(std::size_t i = 0; i < myBlocks.size(); ++i) {
        iNodeData.push_back(myBlocks[i].maxData);
    }
    int iNode = findRange(target, iNodeData);
    if(iNode == -1) {
        position.first = iNode;
        position.second = indexInINode;
        return position;
    }
    indexInINode = findByLoop(target, myBlocks[iNode].data);
    position.first = iNode;
    position.second = indexInINode;
    return position;
}

TEST(Block, testBlockFInd) {
    std::vector<Block<int>> myBlocks = {
        {10, { 7, 3, 2,10, 1}},
        {24, {13,19,24,21,15}},
        {33, {33,29,31,25,32}},
        {99, {45,66,77,88,99}}
    };
    std::pair<int, int> expect;

    //std::cout << "(" << blockFind(45, myBlocks).first << "," << blockFind(45, myBlocks).second << ")" << std::endl;
    expect.first = 3;
    expect.second = 0;
    assert_eq_pair(expect, blockFind(45, myBlocks));

    expect.first = 0;
    expect.second = 0;
    assert_eq_pair(expect, blockFind(7, myBlocks));

    expect.first = 2;
    expect.second = 3;
    assert_eq_pair(expect, blockFind(25, myBlocks));

    expect.first = -1;
    expect.second = -1;
    assert_eq_pair(expect, blockFind(100, myBlocks));

    expect.first = 3;
    expect.second = -1;
    assert_eq_pair(expect, blockFind(55, myBlocks));
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
