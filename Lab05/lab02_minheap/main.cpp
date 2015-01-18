#include <iostream>
#include <vector>
//Current Project
#include "MinHeap.hpp"

template <typename T>
void printVec(const std::vector<T> & vec) {
    for(auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> myvec{80, 57, 99, 35, 23, 11, 74, 29, 62, 16};
    MinHeap<int> heap(myvec);
    printVec(heap.data());

    return 0;
}
