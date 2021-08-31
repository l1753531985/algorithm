#include <iostream>
#include <vector>

using namespace std;

template <typename Object>
class DoubleStack {
private: 
	vector<Object> data;
	int capacity;
	int top1;
	int top2;
public:
	DoubleStack();
	DoubleStack(int);
	~DoubleStack();
	void push1(const Object& value);
	void push2(const Object& value);
	bool isFull();
	bool isEmpty1();
	bool isEmpty2();
	void pop1();
	void pop2();
	const Object& front1();
	const Object& front2();
};

template <typename Object>
DoubleStack<Object>::DoubleStack()
	:top1{0}, top2{0}, capacity{0} {}

template <typename Object>
DoubleStack<Object>::DoubleStack(int cap)
	:top1{0}, top2{cap-1}, capacity{cap}
{
	data.reserve(cap);
}

template <typename Object>
DoubleStack<Object>::~DoubleStack()
{
}

template <typename Object>
void DoubleStack<Object>::push1(const Object& value)
{
	if (isFull()) return;
	data[top1] = value;
	top1++;
}

template <typename Object>
void DoubleStack<Object>::push2(const Object& value)
{
	if (isFull()) return;
	data[top2] = value;
	top2--;
}

template <typename Object>
bool DoubleStack<Object>::isFull()
{
	return (top2 == top1);
}

template <typename Object>
bool DoubleStack<Object>::isEmpty1()
{
	return (top1 == 0);
}

template <typename Object>
bool DoubleStack<Object>::isEmpty2()
{
	return (top2 == capacity-1);
}

template <typename Object>
const Object& DoubleStack<Object>::front1()
{
	if (isEmpty1()) throw "stack1 is empty";
	return data[top1-1];	
}

template <typename Object>
const Object& DoubleStack<Object>::front2()
{
	if (isEmpty2()) throw "stack2 is empty";
	return data[top2+1];	
}

template <typename Object>
void DoubleStack<Object>::pop1()
{
	if (!isEmpty1()) top1--;
}

template <typename Object>
void DoubleStack<Object>::pop2()
{
	if (!isEmpty2()) top2++;
}

int main()
{
	DoubleStack<int> ds{10};
	ds.push1(2);
	ds.push1(3);
	ds.push1(-1);
	ds.push1(33);
	ds.push2(8);
	ds.push2(0);
	ds.push2(9);
	ds.push2(21);
	cout << "top of stack1: " << ds.front1() << endl;
	cout << "top of stack2: " << ds.front2() << endl;
	ds.pop1();
	ds.pop2();
	cout << "top of stack1: " << ds.front1() << endl;
	cout << "top of stack2: " << ds.front2() << endl;
	return 0;
}
