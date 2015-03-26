#pragma once

template <typename T>
void assert_eq_vector(const std::vector<T> & expectVec, const std::vector<T> & vec) {

    typename std::vector<T>::const_iterator vecIter = vec.begin();
    typename std::vector<T>::const_iterator expectVecIter= expectVec.begin();
    while(expectVecIter != expectVec.end()) {
        ASSERT_EQ(*vecIter, *expectVecIter)
            << "expectVec: " << to_string(expectVec) << std::endl
            << "vec: " << to_string(vec);

        ++expectVecIter;
        ++vecIter;
    }//while
}

template <typename T>
std::string to_string(const std::vector<T> & vec) {
    std::ostringstream oss;
    oss << "[";
    for(auto i : vec)
        oss << i << ",";
    oss << "\b]";
    return oss.str();
}
