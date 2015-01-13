#pragma once

template <typename T>
struct NodeInfo {
    BinTreeNode<T> element;
    std::size_t raw;
	std::size_t col;
};
