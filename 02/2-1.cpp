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

int maxSumRec(const vector<int>& a, int left, int right)
{
	if (left == right)
		if (a[left] > 0)
			return a[left];
		else
			return 0;
	int center = (left + right) / 2;
	int maxLeftSum = maxSumRec(a, left, center); 
	int maxRightSum = maxSumRec(a, center+1, right);
	int maxLeftBorderSum = 0, leftBorderSum = 0;
	for (int i = center; i >= left; i--)
	{
		leftBorderSum += a[i];
		if (leftBorderSum > maxLeftBorderSum)
			maxLeftBorderSum = leftBorderSum;
	}

	int maxRightBorderSum = 0, rightBorderSum = 0;
	for (int j = center+1; j <= right; j++)
	{
		rightBorderSum += a[j];
		if (rightBorderSum > maxRightBorderSum)
			maxRightBorderSum = rightBorderSum;
	}

	return maxSumSum(maxLeftSum, maxRightSum, maxLeftBorderSum+maxRightBorderSum);
}

int maxSubSum3(const vector<int>& a)
{
	return maxSumRec(a, 0, a.size()-1);
}

int maxSubSum4(const vector<int>& a)
{
	int maxSum = 0, thisSum = 0;
	for (int j = 0; j < a.size(); j++)
	{
		thisSum += a[j];
		if (thisSum > maxSum)
			maxSum = thisSum;
		else if (thisSum < 0)
			thisSum = 0;
	}
	return maxSum;
}

int main()
{
	vector<int> a{4, -3, 5, -2, -1, 2, 6, -2};
	cout << "func1: " << maxSubSum1(a) << endl;
	cout << "func2: " << maxSubSum2(a) << endl;
	cout << "func3: " << maxSubSum3(a) << endl;
	cout << "func4: " << maxSubSum4(a) << endl;
	return 0;
}
