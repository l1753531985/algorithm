#include <iostream>
#include <stdexcept>
#include <stack>
#include <unistd.h>

using namespace std;

template <typename Object>
class Vector
{
public:
	explicit Vector(int initSize = 0) : theSize(initSize), theCapacity(initSize + SPARE_CAPACITY)
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

	//typedef Object* iterator;
	//typedef const Object* const_iterator;
	class const_iterator
	{
		protected:
			Object* current;
			Object& retrieve() const
			{ return *current; }
			const_iterator(Object* p) : current{p} {}
		public:
			const_iterator() : current(NULL) {}
			const Object& operator*() const 
			{ return retrieve(); }	
			const_iterator& operator++()
			{
				current++;
				return *this;
			}
			const_iterator operator++(int)
			{
				const_iterator old = *this;
				++(*this);
				return old;
			}
			bool operator==(const const_iterator& rhs) const
			{ return *current == *(rhs.current); }
			bool operator!=(const const_iterator& rhs) const
			{ return !(*this == rhs); }
	};

	class iterator : public const_iterator
	{
		public: 
			iterator() {}
			Object& operator*()
			{ return const_iterator::retrieve(); }
			const Object& operator*() const
			{ return const_iterator::operator*(); }
			iterator& operator++()
			{
				current++;
				return *this;
			}

			iterator operator++(int)
			{ 
				iterator old = *this;
				++(*this);
				return old;
			}
		protected:
			iterator(Object* p) : const_iterator(p) {}
	};

	iterator begin()
	{ return &objects[0]; }

	const_iterator begin() const
	{ return &objects[0]; }

	iterator end()
	{ return &objects[size()]; } 

	const_iterator end() const
	{ return &objects[size()]; }

	enum { SPARE_CAPACITY = 16 };

	void insert(const Object& x, int index)
	{
		stack<int> tmp;
		if (index < 0) index = 0; 
		if (index > theSize) index = theSize;
		int times = theSize - index;
		while (times)
		{ 
			//sleep(1);
			tmp.push(back()); 
			pop_back(); 
			times--;
		}
		push_back(x);
		while (!tmp.empty()) 
		{ 
			push_back(tmp.top()); 
			tmp.pop(); 
		}
		theSize++;
	}

	void erase(int index)
	{
		stack<int> tmp;
		if (index < 0 || index > theSize) return;
		int times = theSize - index;
		while (times)
		{ 
			tmp.push(back()); 
			pop_back(); 
			times--;
		}
		tmp.pop();
		while (!tmp.empty()) 
		{ 
			push_back(tmp.top()); 
			tmp.pop(); 
		}
		theSize--;
	}
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
	vi.push_back(7);
	//for (int i = 0; i < vi.size(); i++)
		//cout << vi[i] << endl;
	Vector<int>::iterator viter;
	for (int i = 0; i < vi.size(); i++)
		cout << vi[i] << " ";
	cout << endl;
	vi.insert(-3, -5);
	vi.erase(6);
	for (int i = 0; i < vi.size(); i++)
		cout << vi[i] << " ";
	cout << endl;
	/*
	cout << "what num you want find: ";
	int num = 0;
	cin >> num;
	Vector<int>::iterator res = find(vi.begin(), vi.end(), num);
	if (res == vi.end())
		cout << "not find" << endl;
	else 
		cout << "find it" << endl;
	*/
	return 0;
}


