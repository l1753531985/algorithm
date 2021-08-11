#include <iostream>
#include <vector>

using namespace std;

int maxSubSum1(const vector<int>& a)
{
	int maxSum = 0;
	for (int i = 0; i < a.size(); i++)
		for (int j = i; j < a.size(); j++)
		{
			int thisSum = 0;
			for (int k = i; k <= j; k++)
				thisSum += a[k];
			if (thisSum > maxSum)
				maxSum = thisSum;
		}
	return maxSum;
}

int maxSubSum2(const vector<int>& a)
{
	int maxSum = 0;
	for (int i = 0; i < a.size(); i++)
	{
		int thisSum = 0;
		for (int j = i; j < a.size(); j++)
		{
			thisSum += a[j];
			if (thisSum > maxSum)
				maxSum = thisSum;
		}
	}
}

int ma

int main()
{
	return 0;
}
