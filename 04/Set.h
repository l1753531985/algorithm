#ifndef __SET__H
#define __SET__H

#include <iostream>

using namespace std;

template <typename Comparable>
class Set {
private:
	struct BinaryNode
	{
		Comparable element;
		BinaryNode* left;
		BinaryNode* right;

		BinaryNode(const Comparable& theElement, BinaryNode* lt, BinaryNode* rt)
			:element{theElement}, left{lt}, right{rt} {}
	};

	BinaryNode* root;

	void insert(const Comparable& x, BinaryNode*& t);
	void remove(const Comparable& x, BinaryNode*& t);
	BinaryNode* findMin(BinaryNode* t) const;
	BinaryNode* findMax(BinaryNode* t) const;
	bool contains(const Comparable& x, BinaryNode* t) const;
	void makeEmpty(BinaryNode* t) const;
	void printTree(ostream&, BinaryNode* t) const;
	BinaryNode* clone(BinaryNode* t) const;
public:
	Set();	
	Set(const Set&);
	~Set();
	void makeEmpty() const;
	void printTree(ostream&) const;
	void insert(const Comparable&);
	void remove(const Comparable&);
	const Comparable& findMax() const;
	const Comparable& findMin() const;
};

template <typename Comparable>
Set<Comparable>::Set(const Set& rhs)
	:root{rhs.root}
{
}

template <typename Comparable>
Set<Comparable>::Set()
	:root{nullptr}
{
}

template <typename Comparable>
Set<Comparable>::~Set()
{
	makeEmpty(root);
}


template <typename Comparable>
void Set<Comparable>::makeEmpty() const
{
	makeEmpty(root);
}

template <typename Comparable>
void Set<Comparable>::makeEmpty(BinaryNode* t) const
{
	if (!t) return;
	if (t->left) makeEmpty(t->left);
	if (t->right) makeEmpty(t->right);
	delete t;
}

template <typename Comparable>
void  Set<Comparable>::printTree(ostream& os) const
{
	printTree(os, root);	
	os << "\n" << endl;
}

template <typename Comparable>
void Set<Comparable>::printTree(ostream& os, BinaryNode* t) const
{
	if (t)
	{
		if (t->left) printTree(os,t->left);
		os << t->element << '\t';
		if (t->right) printTree(os,t->right);
	}
}

template <typename Comparable>
void Set<Comparable>::insert(const Comparable& x)
{
	insert(x, root);
}

template <typename Comparable>
void Set<Comparable>::insert(const Comparable& x, BinaryNode*& t)
{
	if (!t) t = new BinaryNode(x, nullptr, nullptr);
	else if (x < t->element) insert(x, t->left);
	else if (x > t->element) insert(x, t->right);
	else;
}

template <typename Comparable>
void Set<Comparable>::remove(const Comparable& x, BinaryNode*& t)
{
	if (!t) return;
	if (x < t->element) remove(x, t->left);
	else if (x > t->element) remove(x, t->right);
	else if (t->left && t->right)
	{
		t->element = findMin(t->right)->element;
		remove(t->element, t->right);
	}
	else
	{
		BinaryNode* oldNode = t;
		t = (t->left) ? t->left : t->right;
		delete oldNode;
	}
}

template <typename Comparable>
void Set<Comparable>::remove(const Comparable& x)
{
	remove(x, root);
}

template <typename Comparable>
typename Set<Comparable>::BinaryNode* Set<Comparable>::findMax(BinaryNode* t) const
{
	if (!t) return nullptr;
	if (!t->right) return t;
	return findMax(t->right);
}

template <typename Comparable>
const Comparable& Set<Comparable>::findMax() const
{
	return *findMax(root);
}

template <typename Comparable>
typename Set<Comparable>::BinaryNode* Set<Comparable>::findMin(BinaryNode* t) const
{
	if (!t) return nullptr;
	if (!t->left) return t;
	return findMin(t->left);
}

template <typename Comparable>
const Comparable& Set<Comparable>::findMin() const
{
	return *findMin(root);
}


#endif
