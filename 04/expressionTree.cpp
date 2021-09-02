#include <iostream>
#include <sstream>

using namespace std;

template <typename Object>
struct Node {
	Object data;
	Node<Object>* left;
	Node<Object>* right;
};

typename <typename Object>
class Tree {
private:
	Node<Object>* TreeHead;
public:
	Tree();
	~Tree();
	void insertLeft(Node<Object>* );
	void insertRight(const Object&);
	void erase(Node<Object>*);
};

typename <typename Object>
Tree<Object>::Tree()
{
	TreeHead = new Node;
	TreeHead->left = nullptr;
	TreeHead->right = nullptr;
}

typename <typename Object>
Tree<Object>::~Tree()
{
	erase(TreeHead);
}

typename <typename Object>
void Tree<Object>::erase(Node<Object>* node)
{
	if (!node) return;
	erase(node->left);
	erase(node->right);
	delete node;
}

typename <typename Object>
void Tree<Object>::insert(const Object& value)
{
	
}

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
