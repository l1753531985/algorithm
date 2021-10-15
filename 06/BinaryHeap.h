#ifndef _BINARYHEAP_H_
#define _BINARYHEAP_H_

#include <vector>
#include <iostream>

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
	const Comparable& getIndex0() const;
	void printHeap(ostream&) const;
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
	array.reserve(items.size() * 2); //allocate empty space
	for (int i = 0; i < items.size(); i++)
		array[i+1] = items[i];
	buildHeap();
}

template <typename Comparable>
void BinaryHeap<Comparable>::insert(const Comparable& x)
{
	if (currentSize == array.size()-1) 	
		array.resize(array.size() * 2); 

	array[0] = x;

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
	Comparable tmp = array[hole];

	for (; hole * 2 < currentSize; hole = child)
	{
		child = hole * 2;
		if (child != currentSize && array[child+1] < array[child])	
			child++;
		if (array[child] < tmp)
			array[hole] = array[child];
		else
			break;
	}
	array[hole] = tmp;
}

template <typename Comparable>
const Comparable& BinaryHeap<Comparable>::getIndex0() const
{
	return array[0];
}

template <typename Comparable>
void BinaryHeap<Comparable>::buildHeap()
{
	for (int i = currentSize/2; i > 0; i--)
		precolateDown(i);
}

template <typename Comparable>
void BinaryHeap<Comparable>::printHeap(ostream& os) const
{
	for (int i = 1; i < currentSize; i++)
		os << array[i] << '\t';
	os << '\n';
}

#endif
