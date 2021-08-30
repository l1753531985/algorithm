#include <stack>
#include <sstream>

enum Priority {FIRST, SECOND, THIRD};

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
