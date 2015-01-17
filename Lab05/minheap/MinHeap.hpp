#pragma once
//Current Project
#include "Assistance.hpp"
template<typename T>
class MinHeap{
private:
	T * heapArr;
	int CurrentSize;
	int MaxSize;
	void FilterDown(int Start);
	void FilterUp(int End);
public :
	MinHeap(int maxSize);
	MinHeap(T a[],int maxsize, int n);
	~MinHeap() {
        delete[] heapArr;
	}
	Status Insert(const T & e);
	Status DeleteTop(T & e);
	Status GetTop(T & e)const;
	bool isEmpty() const;
	bool isFull() const;
	int sizeOfHeap() const;
	void setEmpty();
	void Traverse(void (*Visit)(const T &)) const;
};

#include "MinHeap.tcc"
