#pragma once

//STL
#include <vector>
//Current-Project
#include "UFSetsNode.hpp"

template <typename T>
class UFSets {
private:
    std::vector<UFSetsNode<T>> m_vec;
public:
    UFSets(const std::vector<T> & myvec);
    UFSets(const UFSets & rhs) :
        m_vec(rhs.m_vec)
    {}
    ~UFSets() {}

    std::vector<UFSetsNode<T>> * data() { return &(m_vec); }
    const std::vector<UFSetsNode<T>> * data() const { return &(m_vec); }

    void unionSet(const UFSets<T> & rhs);

    bool find(const T & value);
};

#include "UFSets.tcc"
