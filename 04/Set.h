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
	class const_iterator
	{
		public:
			const_iterator() : current{nullptr} {}
			const Comparable& operator*() const
			{ return retrieve(); }
			const_iterator& operator++()
			{
				current = current->right;
				return *this;
			}
			const_iterator operator++(int)
			{
				const_iterator old = *this;
				++(*this);
				return old;
			}
			const_iterator& operator--()
			{
				current = current->left;
				return *this;
			}
			const_iterator& operator--(int)
			{
				const_iterator old = *this;
				--(*this);
				return old;
			}
			bool operator==(const const_iterator& rhs)
			{ return current == rhs.current; }
			bool operator!=(const const_iterator& rhs)
			{ return !(*this == rhs); }
		protected:
			BinaryNode* current;	
			Comparable& retrieve() const
			{ return current->element; }
			const_iterator(BinaryNode* p)
			{
				current->element = p->element;
				current->left = p->left;
				current->right = p->right;
			}
			friend class Set<Comparable>;
	};
	class iterator : public const_iterator
	{
		public:
			iterator() {}
			Comparable& operator*()
			{ return this->retrieve(); }
			const Comparable& operator*() const 
			{ return const_iterator::operator*(); }
			iterator& operator++()
			{ 
				this->current = this->current->right;
				return *this;
			}
			iterator operator++(int)
			{
				iterator old = *this;
				++(*this);
				return old;
			}
			iterator& operator--()
			{
				this->current = this->current->left;
				return *this;
			}
			iterator& operator--(int)
			{
				iterator old = *this;
				--(*this);
				return old;
			}
		protected:	
			iterator(BinaryNode* p) : const_iterator{p} {}
			friend class Set<Comparable>;
	};
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
	bool isEmpty() const;
	iterator begin()
	{ return iterator(findMin(root)); }
	const_iterator begin() const
	{ return const_iterator(findMin(root)); }
	iterator end()
	{ return iterator(findMax(root)); }
	const_iterator end() const
	{ return const_iterator(findMax(root)); } 
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

template <typename Comparable>
bool Set<Comparable>::isEmpty() const
{
	return (root == nullptr);
}

#endif
