#include <iostream>
#include <cstdlib>
#include <cstdlib>
#include "Set.h"

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
	Set<int>::iterator iter; 
	iter = set.begin();
	for (; iter != set.end(); iter++)
		cout << *iter << endl;
	return 0;
}
