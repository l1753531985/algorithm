#include "FixedCapacityStackOfStrings.h"
#include <iostream>

using namespace std;

int main(int ac, char* argv[])
{
	FixedCapacityStackOfStrings<string> s{100};
	string token;
	while (cin >>token)
	{
		if (token.compare("-"))
			s.push(token);
		else if (!s.isEmpty())
			cout << s.pop() << " " << endl;
	}
	cout << "(" << s.size() << " left on stack)" << endl;
    return 0;
}
