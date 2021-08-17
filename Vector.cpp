#include <iostream>
#include <stdexcept>

using namespace std;

template <typename Object>
class Vector
{
public:
	explicit Vector(int initSize = 0) 
		: theSize(initSize), theCapacity(initSize + SPARE_CAPACITY)
	{ objects = new Object[theCapacity]; }
	Vector(const Vector& rhs) : objects(NULL) { operator=(rhs); }
	~Vector() { delete[] objects; }
	const Vector& operator=(const Vector& rhs)
	{
		if (this != &rhs)
		{
			delete[] objects; 
			theSize = rhs.size();
			theCapacity = rhs.theCapacity;

			objects = new Object[capacity()];
			for (int k = 0; k < size(); k++)
				objects[k] = rhs.objects[k];
		}
		return *this;
	}

	int size() const
	{ return theSize; }

	int capacity() const
	{ return theCapacity; }

	void resize(int newSize)
	{ 
		if (newSize > theCapacity)
			reserve(newSize * 2 + 1);
		theSize = newSize;
	}

	void reserve(int newCapacity)
	{
		if (newCapacity < theSize)
			return;

		Object *oldArray = objects;

		objects = new Object[newCapacity];
		for (int k = 0; k < theSize; k++)
			objects[k] = oldArray[k];

		theCapacity = newCapacity;

		delete[] oldArray;
	}

	Object& operator[](int index)
	{ 
		if (index > theSize || index < 0) throw -1;
		return objects[index]; 
	}

	const Object& operator[](int index) const
	{ 
		if (index > theSize || index < 0) throw -1;
		return objects[index]; 
	}

	bool empty() const
	{ return (size() == 0); }

	void push_back(const Object& x)
	{
		if (theSize == theCapacity)
			reserve(2*theCapacity + 1);
		objects[theSize++] = x;
	}

	void pop_back()
	{ theSize--; }

	const Object& back() const
	{ return objects[theSize-1]; }

	typedef Object* iterator;
	typedef const Object* const_iterator;

	iterator begin()
	{ return &objects[0]; }

	const_iterator begin() const
	{ return &objects[0]; }

	iterator end()
	{ return &objects[size()]; } 

	const_iterator end() const
	{ return &objects[size()]; }

	enum { SPARE_CAPACITY = 16 };
private:	
	int theSize;
	int theCapacity;
	Object *objects;
};

template <typename Iterator, typename Object>
Iterator find(Iterator start, Iterator end, const Object& x)
{
	for (Iterator iter = start; iter != end; iter++)
			if (x == *iter) return iter;
	return end;
}

int main()
{
	Vector<int> vi;	
	vi.push_back(3);
	vi.push_back(2);
	vi.push_back(-1);
	vi.push_back(8);
	vi.push_back(-9);
	vi.push_back(0);
	//for (int i = 0; i < vi.size(); i++)
		//cout << vi[i] << endl;
	Vector<int>::iterator viter;
	cout << "what num you want find: ";
	int num = 0;
	cin >> num;
	Vector<int>::iterator res = find(vi.begin(), vi.end(), num);
	if (res == vi.end())
		cout << "not find" << endl;
	else 
		cout << "find it" << endl;
	return 0;
}


