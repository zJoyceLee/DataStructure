#pragma once
// STL
#include <vector>
// Current Project
#include "LinkedListNode.hpp"

template <typename T>
class LinkedList {
private: // variable
    LinkedListNode<T> * m_data;
private: // 
public: // function
    LinkedList();
    LinkedList(const std::vector<T> & vec);
    ~LinkedList();

    LinkedListNode<T> * & begin() { return m_data; }
    const LinkedListNode<T> * begin() const { return m_data; }

    LinkedListNode<T> * & end() { return nullptr; }
    const LinkedListNode<T> * end() const { return nullptr; }

    void push_front(const T & element);
    void insertBefore(LinkedListNode<T> * position, const T & element);

    void remove(LinkedListNode<T> * position);

    template <typename UnaryFunc>
    LinkedListNode<T> * find(LinkedListNode<T> * startPosition, UnaryFunc checker) const;

    template <typename UnaryFunc>
    void traverse(UnaryFunc visitor);

    template <typename BinaryFunc>
    void swapMinMax(BinaryFunc comparatorLess);
};//class LinkedList

#include "LinkedList.tcc"
