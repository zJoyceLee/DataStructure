//STL
#include <iostream>
//Current Project
#include "LinkedList.hpp"
#include "LinkedListNode.hpp"
//Current test
#include "gtest/gtest.h"

template <typename T>
void printLST(const LinkedList<T> & lst) {
    for(auto cur = lst.begin(); cur != nullptr; cur = cur->next()) {
        std:: cout << cur->data() << ". ";
    }
    std::cout << std::endl;
}

template <typename T>
LinkedList<T> bubbleSort(LinkedList<T> lst) {
    for(auto curj = lst.begin(); curj->next() != nullptr; curj = curj->next()) {
        for(auto cur = lst.begin(); cur->next() != nullptr; cur = cur->next()) {
            if((cur->data()) > (cur->next()->data())) {
//                std::swap(cur->data(), cur->next()->data());

//                // both nodes are between begin and end
//                // second node at the end
                if(cur->prev() != nullptr && cur->next()->next() != nullptr) {
                    auto cur_tmp = cur;
                    //std::cout << "b: " << cur->data() << std::endl;
                    auto tmp = cur->next();
                    //std::cout << "c: " <<  tmp->data() << std::endl;
                    auto prev_tmp = cur->prev();
                    //std::cout << "a: " << prev_tmp->data() << std::endl;
                    auto next_tmp = tmp->next();
                    //std::cout << "d: " << next_tmp->data() << std::endl;
                    prev_tmp->next() = tmp;
                    tmp->next() = cur_tmp;
                    cur_tmp->next() = next_tmp;
                    next_tmp->prev() = cur_tmp;
                    cur_tmp->prev() = tmp;
                    tmp->prev() = prev_tmp;
                    cur = tmp;
                    std::cout << "   in: ";
                    printLST(lst);
                } else if(cur->prev() != nullptr && cur->next() != nullptr && cur->next()->next() == nullptr) {
                    auto cur_tmp = cur;
                    auto tmp = cur->next();
                    auto prev_tmp = cur->prev();
                    prev_tmp->next() = tmp;
                    tmp->next() = cur_tmp;
                    cur_tmp->next() = nullptr;
                    cur_tmp->prev() = tmp;
                    tmp->prev() = prev_tmp;
                    cur = tmp;
                    std::cout << "  end: ";
                    printLST(lst);

                } else if(cur->prev() == nullptr && cur->next()->next() != nullptr) {
                    auto cur_tmp = cur;
                    auto tmp = cur->next();
                    auto next_tmp = tmp->next();
                    tmp->next() = cur_tmp;
                    cur_tmp->next() = next_tmp;
                    next_tmp->prev() = cur_tmp;
                    cur_tmp->prev() = tmp;
                    tmp->prev() = nullptr;
                    cur = tmp;
                    lst.head() = tmp;
                    std::cout << "begin: ";
                    printLST(lst);
                }

            }
        }
    }
    return lst;
}

TEST(BubbleSort, testSort1) {
    LinkedList<int> lst({5,7,3,2,8,4,1,0});
    //bubbleSort(lst);
    printLST(bubbleSort(lst));
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
