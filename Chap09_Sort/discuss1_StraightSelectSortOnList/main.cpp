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
    Node<T> * i_prev, * i;
    Node<T> * iMin_prev, * iMin;
    Node<T> * j = lst.begin(), * j_prev = lst.getHead();
    if(lst.begin() != nullptr) {
        // lst is not empty

        //for(j = lst.begin(); j->next() != lst.end(); j = j->next()) {
        while(j->next() != lst.end()) {
            iMin = j;

            //for(i = j->next(); i != lst.end(); i = i->next()){
            i = j->next();
            while(i != lst.end()) {

                if(i->data() < iMin->data()) {
                    iMin = i;
                    iMin_prev = i_prev;
                }

                i_prev = i;
                i = i->next();
            }

            if(iMin != j) {
                //std::swap(j->data(), iMin->data());
                // we have a head, and it can't change, in the other word: there are one node at the beginning of the list
                //#ifdef changePointer
                if(j->next() == iMin) {
                    j_prev->next() = iMin;
                    iMin->next() = j;
                    j->next() = iMin->next();
                } else if(j->next() == iMin_prev) {
                    auto iMin_next = iMin->next();
                    j_prev->next() = iMin;
                    iMin->next() = iMin_prev;
                    iMin_prev->next() = j;
                    j->next() = iMin_next;
                } else {
                    auto iMin_next = iMin->next();
                    auto j_next = j->next();

                    j_prev->next() = iMin;
                    iMin->next() = j_next;
                    iMin_prev->next() = j;
                    j->next() = iMin_next;
                }
                j = iMin;
                //#endif // changePointer
            }

            j_prev = j;
            j = j->next();
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
