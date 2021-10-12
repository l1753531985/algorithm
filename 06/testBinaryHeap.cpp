#include <iostream>
#include <vector>
#include "BinaryHeap.h"

using namespace std;

int main()
{
	BinaryHeap<int> h;
	vector<int> nums{10, 12, 1, 14, 6, 5, 8, 15, 3, 9, 7, 4, 11, 13, 2};
	for (int i = 0; i < nums.size(); i++)
		h.insert(nums[i]);
	cout << "The min is: " << h.findMin() << endl;
	return 0;
}
