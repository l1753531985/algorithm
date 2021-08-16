#include <iostream>
#include <list>
#include <ctime>
#include <queue>

using namespace std;

template <typename Container>
void printLots1(Container& ct1, Container& ct2)
{
	typename Container::iterator iter1 = ct1.begin();
	for (; iter1 != ct1.end(); iter1++)
	{
		typename Container::iterator iter2 = ct2.begin();
		int index = *iter1;
		while (index)
		{
			iter2++;	
			index--;
		}
		//cout << *iter2 << endl;
	}
}


template <typename Container>
void printLots(Container& ct1, Container& ct2)
{
	typename Container::iterator iter1 = ct1.begin(), iter2 = ct2.begin();
	queue<int> advances, values;

	int advance = 0;
	for (; iter1 != ct1.end(); iter1++) 
	{
		advances.push(*iter1-advance);
		advance = *iter1;
	}

	while (!advances.empty())
	{
		int index = advances.front();
		advances.pop();
		while (index) { iter2++; index--; }
		values.push(*iter2);
	}

	while (!values.empty()) 
	{
		//cout << values.front() << endl;
		values.pop();
	}
}

int main()
{
	const int maxSize = 400000;
	list<int> P, L;
	for (int i = 0; i < maxSize; i++)
		P.push_back(i*3);
	for (int i = 0; i < maxSize*5; i++) 
		L.push_back(i);
	clock_t startTimeQ, endTimeQ;
	startTimeQ = clock();
	printLots(P, L);
	endTimeQ = clock();
	cout << "The runtime of printLots is: " << (double)(endTimeQ-startTimeQ) / CLOCKS_PER_SEC << "s" << endl;

	clock_t startTime, endTime;
	startTime = clock();
	printLots1(P, L);
	endTime = clock();
	cout << "The runtime of printLots1 is: " << (double)(endTime-startTime) / CLOCKS_PER_SEC << "s" << endl;
	return 0;
}
