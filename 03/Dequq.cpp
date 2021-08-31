#include <vector>
#include <iostream>

using namespace std;

template <typename Object>
class Dequq {
private:
	vector<Object> data;
	int capacity;
	int begin;
	int end;
public:
	Dequq(int cap) : begin{0}, end{begin+1}, capacity{cap} { data.reserve(cap); }
	~Dequq() {};
	bool isEmpty();
	bool isFull();
	void push(const Object&);
	void inject(const Object&);
	const Object& pop();
	const Object& eject();
};

template <typename Object>
bool Dequq<Object>::isEmpty()
{
	return (begin+1 == end);
}

template <typename Object>
bool Dequq<Object>::isFull()
{
	return (begin-1 == end);
}

template <typename Object>
void Dequq<Object>::push(const Object& val)
{
	if (isFull()) return;
	data[begin] = val; 	
	if (begin == 0) begin = capacity;
	begin--;
}

template <typename Object>
void Dequq<Object>::inject(const Object& val)
{
	if (isFull()) return;
	data[end] = val;
	if (end == capacity-1) end = -1;
	end++;
}

template <typename Object>
const Object& Dequq<Object>::pop()
{
	if (isEmpty()) throw "nothing to push";
	if (begin == capacity-1) begin = -1;
	const Object& val = data[begin+1];
	begin++;
	return val;
}

template <typename Object>
const Object& Dequq<Object>::eject()
{
	if (isEmpty()) throw "nothing to eject";
	if (end == 0) end = capacity;
	const Object& val = data[end-1];
	end--;
	return val;
}

int main()
{
	Dequq<int> d{8};
	d.inject(-1);
	d.inject(-8);
	d.inject(-3);
	d.push(3);
	d.push(2);
	cout << "pop: " << d.pop() << endl;;
	cout << "eject: " << d.eject() << endl;;
	cout << "pop: " << d.pop() << endl;;
	cout << "eject: " << d.eject() << endl;;
	return 0;
}
