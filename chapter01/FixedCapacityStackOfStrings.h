#include <string>

#ifndef __FIXEDCAPACITYSTACKOFSTRING_H
using namespace std;

template <typename T>
class FixedCapacityStackOfStrings {
public:
    FixedCapacityStackOfStrings(int capacity):index{0},cap{capacity}
	{ array = new T[cap]; }

    ~FixedCapacityStackOfStrings()
	{ delete[] array; }

    void push(T item)
	{
		if (cap == index)
		{
			cap *= 2;
			resize(cap);
		}
		array[index] = item; 
		index++; 
	}

    T pop()
	{ 
		index--; 
		T item = array[index];
		if (index > 0 && index == (cap/4))
		{
			cap /= 2;
			resize(cap);
		}
		return item;
	}

    bool isEmpty() 
	{ return (index == 0); }

    int size()
	{ return index; }

	void resize(int max)
	{ 
		T* temp= new T[max]; 
		for (int i = 0; i < index; i++)
			temp[i] = array[i];
		delete[] array;
		array = temp;
	}
private:
    int index;
	int cap;
    T* array;
};
#endif
