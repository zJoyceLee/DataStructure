#pragma once

template <typename T>
MinHeap<T>::MinHeap(const std::vector<T> & vec) {
    for(auto it = vec.begin(); it != vec.end(); ++it) {
        this->push(*it);
    }
}

template <typename T>
void MinHeap<T>::push(const T & val) {
    m_data.push_back(val);
    std::size_t index = m_data.size() - 1;
    if(index == 0)
        return;
    std::size_t parentIndex = 0;
    do {
        parentIndex = (index - 1) / 2;
        if(m_data[parentIndex] > m_data[index]) {
            std::swap(m_data[parentIndex], m_data[index]);
        }
        index = parentIndex;
    } while(index != 0);
}

template <typename T>
void MinHeap<T>::pop() {
}


