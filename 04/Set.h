#ifndef __SET__H
#define __SET__H

#include "BinarySearchTree.h"

template <typename Comparable>
class Set {
private:
	BinarySearchTree<Comparable>* BiSearchTree;
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
