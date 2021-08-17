#include <iostream>
#include <list>
#include <cstdlib>
#include <ctime>
#include <unordered_set>
#define random(a,b) (rand() % (b-a)+a)

using namespace std;

template <typename Iterator>
void listOrFunc(const Iterator& begin1, const Iterator& end1, const Iterator& begin2, const Iterator& end2, unordered_set<int>& res)
{
	Iterator stopPos, cur;
	if (*begin1 < *begin2) 
	{
		cur = begin1;
		stopPos = begin2;
	}
	else
	{
		cur = begin2;
		stopPos = begin1;
	}

	while (true)
	{
		if (*cur <= *stopPos)
		{
			res.insert(*cur);			
			cur++;
		}
		else
		{
			Iterator tmp = stopPos;
			stopPos = cur;
			cur = tmp;
		} 

		if (cur == end1 || cur == end2) 
		{
			while (stopPos != end1 && stopPos != end2)
			{
				res.insert(*cur);
				stopPos++;
			}
			break;
		}
	}
}

template <typename Iterator>
void listAndFunc(const Iterator& begin1, const Iterator& end1, const Iterator& begin2, const Iterator& end2, unordered_set<int>& res)
{
	Iterator stopPos, cur;
	if (*begin1 < *begin2) 
	{
		cur = begin1;
		stopPos = begin2;
	}
	else
	{
		cur = begin2;
		stopPos = begin1;
	}

	while (true)
	{
		if (*cur == *stopPos)
		{
			res.insert(*cur);			
			cur++;
		}
		else if (*cur < *stopPos)
		{
			cur++;
		}
		else
		{
			Iterator tmp = stopPos;
			stopPos = cur;
			cur = tmp;
		} 
		if (cur == end1 || cur == end2) break;
	}
}

int main()
{
	const int maxSize = 10;
	srand((int)time(0));
	list<int> test1;
	list<int> test2;
	for (int i = 0; i < maxSize; i++) 
	{
		test1.push_back(random(-10, 10));
		test2.push_back(random(-10, 10));
	}

	test1.sort();
	test2.sort();

	unordered_set<int> res;
	listOrFunc(test1.begin(), test1.end(), test2.begin(), test2.end(), res);

	cout << "test1: " << endl;
	for (list<int>::iterator iter = test1.begin(); iter != test1.end(); iter++)
		cout << *iter << " ";
	cout << endl;

	cout << "test2: " << endl;
	for (list<int>::iterator iter = test2.begin(); iter != test2.end(); iter++)
		cout << *iter << " ";
	cout << endl;

	cout << "res: " << endl;
	if (res.empty()) cout << "empty set" << endl;
	else
		for (unordered_set<int>::iterator iter = res.begin(); iter != res.end(); iter++)
			cout << *iter <<endl;

	return 0;
}
