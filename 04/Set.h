#ifndef __SET__H
#define __SET__H

#include "BinarySearchTree.h"

template <typename Comparable>
class Set {
private:
	BinarySearchTree<Comparable>* BiSearchTree;
public:
	class const_iterator
	{
		public:
			const_iterator() : current(nullptr) {}

			const Object& operator*() const 
			{ return retrieve(); }

			const_iterator& operator++()
			{
				current = current->next;
				return *this;
			}

			const_iterator operator++(int)
			{
				const_iterator old = *this;
				++(*this);
				return old;
			}

			bool operator==(const const_iterator& rhs)
			{ return current == rhs.current; }

			bool operator!=(const const_iterator& rhs)
			{ reurn !(*this == rhs); }
		protected:
			Node *current;	

			Object& retrieve() const
			{ return current->data; }

			const_iterator(Node* p) : current {p} {}

			friend class List<Object>;
	}

	class iterator : public const_iterator
	{
		public:
			iterator() {}

			Object& operator*()
			{ return retrieve(); }

			iterator& operator++()
			{
				current = current->next; 
				return *this;
			}
			
			iterator operator++(int)
			{
				iterator old = *this;
				++(*this);
				return old;
			}

		protected:
			iterator(Node* p) : const_iterator{p} {}

			friend class List<Object>;
	}
public:
	Set();	
	Set(const Set&);
	~Set();
};

template <typename Comparable>
Set<Comparable>::Set(const Set& rhs)
	:BiSearchTree{rhs.BiSearchTree}
{
}

template <typename Comparable>
Set<Comparable>::Set()
	:BiSearchTree{new BinarySearchTree<Comparable>}
{
}

template <typename Comparable>
Set<Comparable>::~Set()
{
	delete BiSearchTree;
}




#endif
