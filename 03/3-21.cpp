#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

bool isBlance(const unordered_map<char, char>& table, string raw)
{
	stack<char> checkContainer;
	for (char x : raw)
		switch (x)
		{
			case '(': case '{': case '[':
				checkContainer.push(x);							
				break;
			case ')': case '}': case ']':
				if (checkContainer.empty()) return false;
				if (checkContainer.top() != table.find(x)->second) return false;
				checkContainer.pop();
				break;
			default:
				break;
		}
	if (!checkContainer.empty()) return false;
	return true;
}

int main()
{
	unordered_map<char, char> blanceTable{{'}', '{'}, {']', '['}, {')', '('}};
	string for_test1 = "Pascal(begin/end, (  ), [ ], {}) 。";
	string for_test2 = "C++(/* */,  (), [ ], { }).";
	if (isBlance(blanceTable, for_test1)) cout << "for_test1 is blance" << endl;
	else cout << "for_test1 is not blance" << endl;
	if (isBlance(blanceTable, for_test2)) cout << "for_test2 is blance" << endl;
	else cout << "for_test2 is not blance" << endl;
	return 0;
}
