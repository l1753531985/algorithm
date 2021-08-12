#include <iostream>

using namespace std;

int f(int x)
{
	if (x == 0)
		return 0;
	else
		return 2*f(x-1)+x*x;
}

int bad(int n)
{
	cout << "in bad" << endl;
	if (n == 0)
		return 0;
	else
		return bad(n/3+1) + n - 1;
}

void printDigit(int n)
{
	cout << n << endl;
}

void printOut(int n)
{
	if (n >= 10)
		printOut(n/10);
	printDigit(n % 10);
}

int main()
{
	cout << "input the num you want to calculate:(CTRL+D to end) " << endl;
	int num = 0;
	while (cin >> num)
		printOut(num);
	return 0;
}
