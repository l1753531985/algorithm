#include <iostream>
#include <vector>
#include <time.h>
#include <algorithm>
#include "BinaryHeap.h"

using namespace std;

int main()
{
	vector<int> nums{10, 12, 1, 14, 6, 5, 8, 15, 3, 9, 7, 4, 11, 13, 2};
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size(); i++)
		cout << nums[i] << '\t';
	cout << '\n';

	BinaryHeap<int> h;
	clock_t startInsert = clock();
	for (int i = 0; i < nums.size(); i++)
		h.insert(nums[i]);
	clock_t endInsert = clock();
	cout << "time of inserting to constuct BinaryHeap is: " << (double)(endInsert-startInsert)/CLOCKS_PER_SEC << "s" << endl;
	
	clock_t startConstruct= clock();
	BinaryHeap<int> h2{nums};
	clock_t endConstruct= clock();
	cout << "time of constuct BinaryHeap by vector is: " << (double)(endConstruct-startConstruct)/CLOCKS_PER_SEC << "s" << endl;

	/*
	int deleteElement = 0;
	const int deleteTimes = 8;
	for (int i = 0; i < deleteTimes; i++)
	{
		h.deleteMin(deleteElement);
		cout << deleteElement << endl;
	}
	cout << "The min is: " << h.findMin() << endl;
	*/
	return 0;
}
