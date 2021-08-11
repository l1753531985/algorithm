#include <iostream>
#include <vector>
#include <list>
#include <ctime>

using namespace std;

template <typename Container>
void removeEveryOtherItem(Container& lst)
{
	typename Container::iterator itr = lst.begin();
	while (itr != lst.end())
	{
		itr = lst.erase(itr);
		if (itr != lst.end())
			++itr;
	}
}

int main()
{
	cout << "input capacity of container: " << endl;
	int capacity = 0;
	cin >> capacity; 
	// cout << "capacity: " << capacity << endl;
	vector<int> va{capacity};
	list<int> la{capacity};

	for (int i = 0; i < capacity; i++)
	{
		va.push_back(i);
		la.push_back(i);
	}

	clock_t startTimeL, endTimeL;
	startTimeL = clock();
	removeEveryOtherItem(la);
	endTimeL = clock();
	cout << "The run time of list is: " << (double)(endTimeL-startTimeL) / CLOCKS_PER_SEC << "s" << endl;

	clock_t startTimeV, endTimeV;
	startTimeV = clock();
	removeEveryOtherItem(va);
	endTimeV = clock();
	cout << "The run time of vector is: " << (double)(endTimeV-startTimeV) / CLOCKS_PER_SEC << "s" << endl;

	return 0;
}
