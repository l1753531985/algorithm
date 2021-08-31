#include <stack>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>

using namespace std;

enum Priority {FIRST, SECOND, THIRD, ZERO};

class FixConvert {
private:
	string expression;
	stack<string> hang;
	string expressionInPostFix;
	unordered_map<string, Priority> priorityTable;
	void convert();
public:
	FixConvert();
	FixConvert(string);
	~FixConvert();
	string getPostFixExpression();
};
