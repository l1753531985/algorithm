#include <iostream>
#include <list>
#include <vector>

using namespace std;

template <typename Container>
void printCollection(const Container& c, ostream& out = cout)
{
	if (c.empty())
		cout << "(empty)";
	else
	{
		typename Container::const_iterator itr = c.begin();
		out << "[ " << *itr++;
		while (itr != c.end())
			out << ", " << *itr++;
		out << " ]" << endl;
	}
}

int main()
{
	vector<int> va(10, 1);
	list<int> la(10, -1);
	printCollection(va);
	printCollection(la);
	return 0;
}
