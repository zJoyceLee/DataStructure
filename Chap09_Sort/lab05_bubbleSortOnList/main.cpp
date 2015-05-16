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
void print(const LinkedList<T> & lst) {
    std::cout << '{' << std::endl;
    for (auto i = lst.begin(); i != lst.end(); i = i->next()) {
        std::cout << "  (" << i->data() << ',' << i->prev() << ',' << i->next() << ")" << std::endl;
    }
    std::cout << '}' << std::endl;
}

template <typename T>
std::size_t to_index(const LinkedList<T> & lst, LinkedListNode<T> * node) {
    std::size_t ret = 0;
    for(auto i = lst.begin(); i != lst.end(); i = i->next()) {
        if(i == node)
            break;
        ++ret;
    }
    return ret;
}

template <typename T>
LinkedList<T> bubbleSort(LinkedList<T> lst) {
#if 0
    for(auto curj = lst.begin(); curj->next() != nullptr; curj = curj->next()) {
        for(auto cur = lst.begin(); cur->next() != nullptr; cur = cur->next()) {
            if((cur->data()) > (cur->next()->data())) {
//                std::swap(cur->data(), cur->next()->data());

                // both nodes are between begin and end
                // second node at the end
                // third node at the begin
                // only two nodes
                if(cur->prev() != nullptr && cur->next()->next() != nullptr) {
                    auto cur_tmp = cur;
                    auto tmp = cur->next();
                    auto prev_tmp = cur->prev();
                    auto next_tmp = tmp->next();
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
                } else if(cur->prev() == nullptr && cur->next() != nullptr && cur->next()->next() == nullptr) {
                    auto cur_tmp = cur;
                    auto tmp = cur->next();
                    tmp->next() = cur_tmp;
                    cur_tmp->next() = nullptr;
                    cur->prev() = tmp;
                    tmp->prev() = nullptr;
                    cur = tmp;
                    lst.head() = tmp;
                    printLST(lst);
                }

            }
        }
    }
    return lst;
#endif
    print(lst);
    auto i = lst.begin();
    auto j = lst.begin();
    while(i->next() != nullptr) {
        auto inext = i->next();
        while(j->next() != nullptr) {
            auto cur = j;
            auto next = j->next();

            if(cur->data() > next->data()) {

                if(cur->prev() == nullptr && next->next() == nullptr) {
                    // case 1: only 2 nodes
                    next->next() = cur; cur->prev() = next;
                    next->prev() = nullptr; cur->next() = nullptr;
                    // change the first node
                    lst.head() = next;

                    j = cur;
                } else if(cur->prev() == nullptr) {
                    // case 2: swap the first node and the second node
                    auto n = next->next();
                    next->prev() = nullptr;
                    cur->next() = n; n->prev() = cur;
                    next->next() = cur; cur->prev() = next;
                    // change the first node
                    lst.head() = next;

                    j = cur;
                } else if(next->next() == nullptr) {
                    // case 3: swap the last node and the node before last
                    auto p = cur->prev();
                    cur->next() = nullptr;
                    next->prev() = p; p->next() = next;
                    next->next() = cur; cur->prev() = next;

                    j = cur;
                } else {
                    // normal case
                    auto p = cur->prev(); auto n = next->next();
                    next->prev() = p; p->next() = next;
                    cur->next() = n; n->prev() = cur;
                    next->next() = cur; cur->prev() = next;

                    j = cur;
                }
            }
            j = next;
        }
        i = inext;
    }

    return lst;
}

TEST(BubbleSort, teatSortOneNode) {
    LinkedList<int> lst({1});
    printLST(bubbleSort(lst));
}

TEST(BubbleSort, testSortTwoNodes) {
    LinkedList<int> lst({99,1});
    printLST(bubbleSort(lst));
}

TEST(BubbleSort, teatSortThreeNodes1) {
    LinkedList<int> lst({92,1,3});
    printLST(bubbleSort(lst));
}

TEST(BubbleSort, teatSortThreeNodes2) {
    LinkedList<int> lst({92,1,0});
    printLST(bubbleSort(lst));
}

TEST(BubbleSort, testSortMoreThanThreeNodes) {
    LinkedList<int> lst({5,7,3,2,8,4,1,0});
    printLST(bubbleSort(lst));
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
