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
	vector<int> va(capacity, 1);
	list<int> la(capacity, 1);

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
