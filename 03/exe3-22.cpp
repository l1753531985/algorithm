#include <iostream>
#include <stack>
#include <sstream>

using namespace std;

template <typename Object>
void calculate(stack<Object>& data, string elem)
{
	stringstream word{elem};
	stringstream word_copy{elem};
	Object obj;
	if (word >> obj) 
		data.push(obj);
	else
	{
		Object second = data.top();
		data.pop();
		Object first = data.top();
		data.pop();
		Object res;
		char op;
		word_copy >> op;
		switch (op)
		{
			case '+':
				res = first + second;
				break;
			case '-':
				res = first - second; 
				break;
			case '*':
				res = first * second;
				break;
			case '/':
				res = first / second;
				break;
			default:
				break;
		}
		data.push(res);
	}
}

int main()
{
	stringstream expression{"6 5 2 3 + 8 * + 3 + *"};
	stringstream expression2{"4.99 * 1.06 + 5.99 + 6.99 * 1.06"};
	//stack<int> data;
	stack<double> data;
	string singleWord = "";
	while (expression2 >> singleWord)
	{
		cout << singleWord << endl;
		calculate(data, singleWord);
	}
	cout << data.top() << endl;
	return 0;
}
