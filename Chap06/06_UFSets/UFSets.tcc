#pragma once

template <typename T>
UFSets<T>::UFSets(const std::vector<T> & myvec) {
    if (myvec.size() == 0)
        return;

    for(auto it = myvec.begin(); it != myvec.end(); ++it) {
        m_vec.push_back(UFSetsNode<T> {*it, 0});
    }
    m_vec[0].parentIndex = -myvec.size();
}

template <typename T>
void UFSets<T>::unionSet(const UFSets<T> & rhs) {
    if(rhs.data()->size() == 0)
        return;

    std::vector<UFSetsNode<T>> rhsVec = *(rhs.data());
    rhsVec[0].parentIndex = 0;
    for(std::size_t i = 1; i < rhsVec.size(); ++i) {
        rhsVec[i].parentIndex = m_vec.size();
    }
    for(auto it = rhsVec.begin(); it != rhsVec.end(); ++it) {
        m_vec.push_back(*it);
    }
    m_vec[0].parentIndex = -m_vec.size();
}

template <typename T>
void UFSets<T>::unionSetByNodeNum(const UFSets<T> & rhs) {
    if(rhs.data()->size() == 0)
        return;
    if(rhs.data()->size() <= this->data()->size()) {
       (*this).unionSet(rhs);
    } else {
        rhs.unionSet((*this));//how?
    }

}

template <typename T>
bool UFSets<T>::find(const T & value) {
    for(std::size_t i = 0; i < m_vec.size(); ++i) {
        if(m_vec[i].data == value)
            return true;
    }
    return false;
}

template <typename T>
std::size_t UFSets<T>::findAll(const T & value, const std::vector<UFSets<T>> & vec) {
    for(std::size_t i = 0; i < vec.size(); ++i) {
        if(find(value) == true) {
            return i;
        }
    }
}
