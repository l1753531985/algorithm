#ifndef _BINARYHEAP_H_
#define _BINARYHEAP_H_

#include <vector>

using namespace std;

template <typename Comparable>
class BinaryHeap {
public:
	explicit BinaryHeap(int capacity = 100); 
	explicit BinaryHeap(const vector<Comparable>&); 
	
	bool isEmpty();
	const Comparable& findMin() const;
	void insert(const Comparable&);
	void deleteMin();
	void deleteMin(Comparable&);
	void makeEmpty();
private:
	int currentSize;
	vector<Comparable> array;
	void buildHeap();
	void precolateDown(int);
};

template <typename Comparable>
BinaryHeap<Comparable>::BinaryHeap(int capacity)
	:currentSize{0}
{
	array.reserve(capacity);
}

template <typename Comparable>
BinaryHeap<Comparable>::BinaryHeap(const vector<Comparable>& items)
	:currentSize{items.size()}
{
	if (currentSize < items.size()-1)
		array.resize(items.size() * 2);
	for (Comparable x : items)
		array.push_back(x);
}

template <typename Comparable>
void BinaryHeap<Comparable>::insert(const Comparable& x)
{
	if (currentSize == array.size()-1) 	
		array.resize(array.size() * 2); 

	int hole = ++currentSize;
	for (; hole > 1 && x < array[hole/2]; hole /= 2)
		array[hole] = array[hole/2];
	array[hole] = x;
	//cout << "hole: " << hole << "\tvalue: " << x << endl; 
}

template <typename Comparable>
const Comparable& BinaryHeap<Comparable>::findMin() const
{
	return array[1];
}

template <typename Comparable>
bool BinaryHeap<Comparable>::isEmpty()
{
	return (currentSize == 0);
}

template <typename Comparable>
void BinaryHeap<Comparable>::deleteMin()
{
	if (isEmpty()) return;//throw UnderflowException(Comparable); 
	array[1] = array[currentSize--];
	precolateDown(1);
}

template <typename Comparable>
void BinaryHeap<Comparable>::deleteMin(Comparable& minItem)
{
	if (isEmpty()) return;
	minItem = array[1];
	array[1] = array[currentSize--];
	precolateDown(1);
}

template <typename Comparable>
void BinaryHeap<Comparable>::precolateDown(int hole)
{
	int child;  	
	Comparable tmp = array[child];

	for (; hole * 2 < currentSize; hole = child)
	{
		child = hole * 2;
		if (child != currentSize && array[child] < array[child+1])	
			child++;
		if (array[child] < array[hole])
			array[hole] = array[child];
		else
			break;
	}
	array[hole] = tmp;
}

#endif
