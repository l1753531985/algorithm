#include <iostream>
#include <cstdlib>
#include "Set.h"
#include <cstdlib>

using namespace std;

int main()
{
	Set<int> set;
	const int maxSize = 10;
	const int maxNum = 100;
	for (int i = 0; i < maxSize; i++)
	{
		int num = rand() % maxNum;
		set.insert(num);
	}
	set.printTree(cout);
	int j = 0;
	while (cin >> j) 
	{
		set.remove(j);
		set.printTree(cout);
	}
	return 0;
}
