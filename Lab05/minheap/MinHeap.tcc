#pragma once

template <typename T>
MinHeap<T>::MinHeap(int maxSize) {
    if (maxSize <= 0)		{
	    std::cerr << "Heap's max size should be positive." << std::endl;
        exit(1);
    }
	MaxSize = maxSize;
	heapArr = new T[MaxSize];
	CurrentSize = 0;
}

template <typename T>
MinHeap<T>::MinHeap(T a[],int maxSize, int n) {
	if(n <= 0)	{
	    std::cerr << "Heap's max size should be positive." << std::endl;
        exit(1);
    }
	MaxSize = maxSize;
	heapArr = new T [MaxSize];
	for (int i = 0; i < n; i++)
        heapArr[i] = a[i];
	CurrentSize = n;
	int i = (CurrentSize - 2) / 2;
	while(i >= 0)	{
        FilterDown(i);
		i--;
		Traverse(Write<T>);
		std::cout << std::endl;
	}
}

template <typename T>
MinHeap<T>::~MinHeap()  {
    delete[] heapArr;
}

template <typename T>
void MinHeap<T>::FilterDown(const int Start) {
	int i = Start,j;
	T temp = heapArr[i];
	j = 2 * i + 1;
	while(j <= CurrentSize - 1)		{
		if(j < CurrentSize - 1 && heapArr[j] > heapArr[j+1])
			j++;
		if(temp <= heapArr[j]) break;
		else {
			heapArr[i] = heapArr[j];
			i = j;
            j = 2*j+1;
		}
	}
	heapArr[i] = temp;
}

template <typename T>
void MinHeap<T>::FilterUp(int End) {
	int j = End,i;
	T temp = heapArr[j];
	i = (j - 1) / 2;
	while(j > 0)	{
		if (heapArr[i] <= temp) break;
		else {
			heapArr[j] = heapArr[i];
			j = i;
			i = (j - 1) / 2;
		}
		heapArr[j] = temp;
	}
}

template <typename T>
Status MinHeap<T>::Insert(const T & e) {
	if (isFull())
		return OVER_FLOW;
	heapArr[CurrentSize] = e;
	FilterUp(CurrentSize);
	CurrentSize++;
	return SUCCESS;
}

template <typename T>
Status MinHeap<T>::DeleteTop(T & e) {
	if(isEmpty())
    	return UNDER_FLOW;
	e = heapArr[0];
	heapArr[0] = heapArr[CurrentSize-1];
	CurrentSize--;
	FilterDown(0);
	return SUCCESS;
}

template <typename T>
Status MinHeap<T>::GetTop(T & e) const {
	if(isEmpty())
    	return UNDER_FLOW;
	e = heapArr[0];
	return SUCCESS;
}

template <typename T>
bool MinHeap<T>::isEmpty() const {
    return CurrentSize == 0;
}

template <typename T>
bool MinHeap<T>::isFull() const {
    return CurrentSize == MaxSize;
}

template <typename T>
int MinHeap<T>::sizeOfHeap() const {
     return CurrentSize;
}

template <typename T>
void MinHeap<T>::setEmpty() {
    CurrentSize = 0;
}

template<typename T>
void MinHeap<T>::Traverse(void (*Visit)(const T &)) const {
	for(int i = 0; i < CurrentSize; i++)
		(*Visit)(heapArr[i]);
}

