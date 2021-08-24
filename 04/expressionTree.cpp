#include <iostream>
#include <sstream>

using namespace std;

template <typename Object>
struct Node {
	Object element;
	Node* left;
	Node* right;
};

class Tree {
};

int main()
{
	string expression = "a b + c d e + * *";
	stringstream data{expression};	
	string singleExpression = "";
	while (data >> singleExpression)
	{
		cout << singleExpression << '\t';
	}
	cout << endl;
	return 0;
}
