#include <iostream>
#include <stack>
#include <sstream>

using namespace std;

template <typename Object>
struct Node {
	Object data;
	Node<Object>* left;
	Node<Object>* right;
};

void createExpressionTree(string expression, stack<Node<string>*>& dataStore)
{
	stringstream data{expression};	
	char singleExpression;
	while (data >> singleExpression)
	{
		string tmp = "";
		tmp.push_back(singleExpression);
		Node<string>* n = new Node<string>;
		n->data = tmp;
		if (ispunct(singleExpression))
		{
			n->right = dataStore.top();
			dataStore.pop();
			n->left = dataStore.top();
			dataStore.pop();
		}
		dataStore.push(n);
	}
}

template <typename Object>
void traverseTree(Node<Object>* node)
{
	delete node;
	if (!node->left && !node->right) return;
	traverseTree(node->left);
	traverseTree(node->right);
}

int main()
{
	string expression = "a b + c d e + * *";
	stack<Node<string>*> dataStore;
	createExpressionTree(expression, dataStore);
	traverseTree(dataStore.top());
	return 0;
}
