//STL
#include <iostream>
//Current Project
#include "Node.hpp"
#include "LinkedList.hpp"
//current test
#include "gtest/gtest.h"

template <typename T>
void print(const LinkedList<T> & lst) {
    std::cout << '{' << std::endl;
    for (auto i = lst.begin(); i != lst.end(); i = i->next()) {
        std::cout << "  (" << i->data() << ',' << i->prev() << ',' << i->next() << ")" << std::endl;
    }
    std::cout << '}' << std::endl;
}

namespace std {
    template <typename T>
    std::string to_string(const LinkedList<T> & lst) {
        std::string ret;
        ret += '[';
        for (auto i = lst.begin(); i != lst.end(); i = i->next()) {
            ret += std::to_string(i->data());
            ret += ',';
        }

        if(ret.back() == ',') {
            ret.back() = ']';
        } else {
            ret += ']';
        }
        return ret;
    }
}

#ifdef array
/* a[0] to a[n-1] is the array to sort */
int i,j;
int iMin;

/* advance the position through the entire array */
/*   (could do j < n-1 because single element is also min element) */
for (j = 0; j < n-1; j++) {
    /* find the min element in the unsorted a[j .. n-1] */

    /* assume the min is the first element */
    iMin = j;
    /* test against elements after j to find the smallest */
    for ( i = j+1; i < n; i++) {
        /* if this element is less, then it is the new minimum */
        if (a[i] < a[iMin]) {
            /* found new minimum; remember its index */
            iMin = i;
        }
    }

    if(iMin != j) {
        swap(a[j], a[iMin]);
    }
}
#endif // array

template <typename T>
LinkedList<T> selectSort(LinkedList<T> lst) {
    auto i_prev = lst.begin(), i = i_prev->next();
    auto iMin_prev = lst.begin(), iMin = iMin_prev->next();
    Node<T> * j = lst.begin();
    if(lst.begin()->next() != nullptr) {
        // lst is not empty
        for(j = lst.begin()->next(); j->next() != lst.end(); j = j->next()) {
            iMin = j;
            while(i->next() != nullptr) {
                i_prev = i;
                i = j->next();

                if(i->data() < iMin->data()) {
                    iMin = i;
                    iMin_prev = i_prev;
                }
            }
            if(iMin != j) {
                std::swap(j->data(), iMin->data());
            }
        }

    }
    return lst;
}

TEST(LinkedList, testConstruct) {
    LinkedList<int> lst({1,2,3,4});
}

TEST(selectSort, testSortOneNode) {
    EXPECT_EQ("[1]", std::to_string(selectSort(LinkedList<int>({1}))));
}

TEST(selectSort, testSortTwoNodes) {
    EXPECT_EQ("[1,99]", std::to_string(selectSort(LinkedList<int>({99,1}))));
    EXPECT_EQ("[1,99]", std::to_string(selectSort(LinkedList<int>({1,99}))));
}

TEST(selectSort, teatSortThreeNodes1) {
    EXPECT_EQ("[1,3,92]", std::to_string(selectSort(LinkedList<int>({92,1,3}))));
    EXPECT_EQ("[1,3,92]", std::to_string(selectSort(LinkedList<int>({92,1,3}))));
    EXPECT_EQ("[1,3,92]", std::to_string(selectSort(LinkedList<int>({1,92,3}))));
    EXPECT_EQ("[1,3,92]", std::to_string(selectSort(LinkedList<int>({3,92,1}))));
    EXPECT_EQ("[1,3,92]", std::to_string(selectSort(LinkedList<int>({1,3,92}))));
    EXPECT_EQ("[1,3,92]", std::to_string(selectSort(LinkedList<int>({3,1,92}))));
}

TEST(selectSort, teatSortThreeNodes2) {
    EXPECT_EQ("[0,1,92]", std::to_string(selectSort(LinkedList<int>({92,1,0}))));
    EXPECT_EQ("[0,1,92]", std::to_string(selectSort(LinkedList<int>({92,0,1}))));
    EXPECT_EQ("[0,1,92]", std::to_string(selectSort(LinkedList<int>({1,92,0}))));
    EXPECT_EQ("[0,1,92]", std::to_string(selectSort(LinkedList<int>({0,92,1}))));
    EXPECT_EQ("[0,1,92]", std::to_string(selectSort(LinkedList<int>({1,0,92}))));
    EXPECT_EQ("[0,1,92]", std::to_string(selectSort(LinkedList<int>({0,1,92}))));
}

TEST(selectSort, testSortMoreThanThreeNodes) {
    LinkedList<int> lst({5,7,3,2,8,4,1,0});
    EXPECT_EQ("[0,1,2,3,4,5,7,8]", std::to_string(selectSort(LinkedList<int>({5,7,3,2,8,4,1,0}))));
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
