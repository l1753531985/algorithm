#ifndef __binarysearchtree__H
#define __binarysearchtree__H

#include <iostream>

using namespace std;

template <typename Comparable>
class BinarySearchTree {
public:
	BinarySearchTree();
	BinarySearchTree(const BinarySearchTree& rhs);
	~BinarySearchTree();

	const Comparable& findMin() const;
	const Comparable& findMax() const;
	bool contains(const Comparable& x) const;
	bool isEmpty() const
	{ return (root == nullptr); }
	void printTree(ostream& os) const;

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

	void insert(const Comparable& x, BinaryNode*& t);
	void remove(const Comparable& x, BinaryNode*& t);
	BinaryNode* findMin(BinaryNode* t) const;
	BinaryNode* findMax(BinaryNode* t) const;
	bool contains(const Comparable& x, BinaryNode* t) const;
	void makeEmpty(BinaryNode*& t);
	void printTree(ostream&, BinaryNode* t) const;
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
	makeEmpty();
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
const Comparable& BinarySearchTree<Comparable>::findMin() const
{
	return findMin(root)->element;
}

template <typename Comparable>
typename BinarySearchTree<Comparable>::BinaryNode* BinarySearchTree<Comparable>::findMin(BinaryNode* t) const
{
	if (!t) return nullptr;
	if (!t->left) return t;
	findMin(t->left);
}

template <typename Comparable>
const Comparable& BinarySearchTree<Comparable>::findMax() const
{
	return findMax(root)->element;
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
	else;
}

template <typename Comparable>
void BinarySearchTree<Comparable>::remove(const Comparable& x, BinaryNode*& t)
{
	if (!t) return;
	if (x < t->element) remove(x,t->left);
	else if (x > t->element) remove(x,t->right);
	else if (t->left && t->right)
	{
		t->element = findMin(t->right)->element;
		remove(t->element,t->right);
	}
	else
	{
		BinaryNode* oldNode = t;
		t = (t->left) ? t->left : t->right;
		delete oldNode;
	}
}

template <typename Comparable>
void BinarySearchTree<Comparable>::makeEmpty()
{
	makeEmpty(root);
}

template <typename Comparable>
void BinarySearchTree<Comparable>::makeEmpty(BinaryNode*& t)
{
	if (t)
	{
		makeEmpty(t->left);
		makeEmpty(t->right);
		delete t;
	}
	t = nullptr;
}

template <typename Comparable>
const BinarySearchTree<Comparable>& BinarySearchTree<Comparable>::operator=(const BinarySearchTree& rhs)
{
	if (this != &rhs)
	{
		makeEmpty();
		root = clone(rhs.root);
	}
	return *this;
}

template <typename Comparable>
typename BinarySearchTree<Comparable>::BinaryNode* BinarySearchTree<Comparable>::clone(BinaryNode* t) const
{
	if (!t) return nullptr;
	return new BinaryNode(t->element, clone(t->left), clone(t->right));
}

template <typename Comparable>
void BinarySearchTree<Comparable>::printTree(ostream& os) const
{
	printTree(os, root);
}

template <typename Comparable>
void BinarySearchTree<Comparable>::printTree(ostream& os, BinaryNode* t) const
{
	if (t)
	{
		printTree(os, t->left);
		os << t->element << '\t';
		printTree(os, t->right);
	}
	cout << "\n";
}

#endif
