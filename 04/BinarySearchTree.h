#ifndef __binarysearchtree__H
#define __binarysearchtree__H

template <typename Comparable>
class BinarySearchTree {
public:
	BinarySearchTree();
	BinarySearchTree(const BinarySearchTree& rhs);
	~BinarySearchTree();

	const Comparable& findMin() const;
	const Comparable& findMax() const;
	bool contains(const Comparable& x) const;
	bool isEmpty() const;
	void printTree() const;

	void makeEmpty();
	void insert(const Comparable& x);
	void remove(const Comparable& x);
	const BinarySearchTree& operator=(const BinarySearchTree& rhs);
private:
	struct BinaryNode
	{
		Comparable element;
		BinaryNode* left;
		BinaryNode* right;

		BinaryNode(const Comparable& theElement, BinaryNode* lt, BinaryNode* rt)
			: element{theElement}, left{lt}, right{rt} {}
	};

	BinaryNode* root;

	void insert(const Comparable& x, BinaryNode*& t) const;
	void remove(const Comparable& x, BinaryNode*& t) const;
	BinaryNode* findMin(BinaryNode* t) const;
	BinaryNode* findMax(BinaryNode* t) const;
	bool contains(const Comparable& x, BinaryNode* t) const;
	void makeEmpty(BinaryNode*& t);
	void printTree(BinaryNode* t) const;
	BinaryNode* clone(BinaryNode* t) const;
};

template <typename Comparable>
BinarySearchTree<Comparable>::BinarySearchTree()
	:root{nullptr}
{
}

template <typename Comparable>
BinarySearchTree<Comparable>::~BinarySearchTree()
{
	delete root;
}

template <typename Comparable>
BinarySearchTree<Comparable>::BinarySearchTree(const BinarySearchTree& rhs)
	:root{rhs.root}
{
}

template <typename Comparable>
bool BinarySearchTree<Comparable>::contains(const Comparable& x) const
{
	return contains(x, root);
}

template <typename Comparable>
void BinarySearchTree<Comparable>::insert(const Comparable& x)
{
	insert(x, root);
}

template <typename Comparable>
void BinarySearchTree<Comparable>::remove(const Comparable& x)
{
	remove(x, root);
}

template <typename Comparable>
bool BinarySearchTree<Comparable>::contains(const Comparable& x, BinaryNode* t) const
{
	if (!t) return false;
	else if (x < t->element) return contains(x, t->left);
	else if (x > t->element) return contains(x, t->right);
	else return true;
}

template <typename Comparable>
typename BinarySearchTree<Comparable>::BinaryNode* BinarySearchTree<Comparable>::findMin(BinaryNode* t) const
{
	if (!t) return nullptr;
	if (!t->left) return t;
	findMin(t->left);
}

template <typename Comparable>
typename BinarySearchTree<Comparable>::BinaryNode* BinarySearchTree<Comparable>::findMax(BinaryNode* t) const
{
	if (t) 
		while (t->right)
			t = t->right;
	return t;
}

template <typename Comparable>
void BinarySearchTree<Comparable>::insert(const Comparable& x, BinaryNode*& t)
{
	if (!t) t = new BinaryNode(x, nullptr, nullptr);
	else if (x < t->element) insert(x, t->left);
	else if (x > t->element) insert(x, t->right);
	else ;
}

#endif
