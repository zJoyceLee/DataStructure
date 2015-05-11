//STL
#include <iostream>
#include <vector>
#include <array>
//Current Project
#include "helper.hpp"
//g-test
#include "gtest/gtest.h"

template <typename T>
void printVec(const std::vector<T> & vec) {
    for(std::size_t i = 0; i < vec.size() - 1; ++i) {
        std::cout << vec[i] << ", ";
    }
    std::cout << vec[vec.size() - 1] << std::endl;
}


std::size_t myHash(int key) {
    std::size_t position = (3 * key) % 11;
    return position;
}

std::size_t myReHash(int key) {
    std::size_t position = (7 * key) % 10 + 1;
    return position;
}

std::size_t conflict(int key, std::size_t m, std::size_t i) {
    std::size_t position = (myHash(key) + i * myReHash(key)) % m;
    // in this case m = 11, i is increasing from 1 to m - 1
    return position;
}

TEST(Hash, testHash) {
    std::vector<int> myvec = {22,41,53,46,30,13,1,67};
    std::vector<std::size_t> hashResult;
    for (std::size_t i = 0; i < myvec.size(); ++i) {
        hashResult.push_back(myHash(myvec[i]));
    }
    assert_eq_vector({0,2,5,6,2,6,3,3}, hashResult);

}

TEST(Hash, testConstruct) {
    std::vector<std::pair<int, bool>> myvec;
    for(std::size_t i = 0; i < 11; ++i){
        myvec.push_back({0, false});
    }; // initialization
    std::vector<int> mykeys = {22,41,53,46,30,13,1,67};

    for(std::size_t index = 0; index < mykeys.size(); ++index) {
        int key = mykeys[index]; // index is increasing
        std::size_t position = myHash(key);
        std::size_t rePosition = myvec.size();
         if(myvec[position].second == false) {
            myvec[position] = {key, true};
        } else {
            std::size_t i = 1;
            do{
                rePosition = conflict(key, 11, i);
                ++i;
            } while(myvec[rePosition].second == true);
            myvec[rePosition] = {key, true};
        }
    } // (1) construct

    ///{{22,true},{67,true},{41,true},{30,true},{0, false},{53,true},{46,true},{0, false},{13,true},{0, false},{1,true}}
    std::vector<int> resultVec;
    for(std::size_t i = 0; i < myvec.size(); ++i) {
        resultVec.push_back(myvec[i].first);
    }
    assert_eq_vector({ 22, 67, 41, 30,  0, 53, 46,  0, 13,  0,  1}, resultVec);
}



int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
