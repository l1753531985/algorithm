#include <iostream>

using namespace std;

class IntCell
{
public:
	explicit IntCell(int initialValue = 0) : storedValue{initialValue} {}
	int read() const
	{ return storedValue; }
	void write(int x)
	{ storedValue = x; }
private:
	int storedValue;
};

int main()
{
	IntCell obj;
	obj = 37;
	cout << obj.read() << endl;
	return 0;
}
