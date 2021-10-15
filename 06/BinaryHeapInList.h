#include <vector>

using namespace std;

template <typename Comparable>
class BinaryHeapInList {
public:
	BinaryHeapInList();
	BinaryHeapInList(const vector<Comparable>&);
	~BinaryHeapInList();

	bool isEmpty();
	const Comparable& findMin() const;
	void insert(const Comparable&);
	void deleteMin();
	void deleteMin(Comparable&);
private:
	struct BinaryHeapNode
	{
		Comparable element;	
		BinaryHeapNode* left;
		BinaryHeapNode* right;

		BinaryHeapNode(const Comparable& x, BinaryHeapNode* lt, BinaryHeapNode* rt)
			: element{x}, lt{left}, rt{right} {}
	};

	BinaryHeapNode* root;

	void insert(BinaryHeapNode*, const Comparable&);
	BinaryHeapNode* getLastNode(BinaryHeapNode*);
};

template <typename Comparable>
BinaryHeapInList<Comparable>::BinaryHeapInList()
	:root{nullptr} {}

template <typename Comparable>
void BinaryHeapInList<Comparable>::insert(const Comparable& x)
{
	 insert(root, x);
}

template <typename Comparable>
void BinaryHeapInList<Comparable>::insert(BinaryHeapNode* t, const Comparable& x)
{
	if (!t) return;
}

template <typename Comparable>
typename BinaryHeapInList<Comparable>::BinaryHeapNode* BinaryHeapInList<Comparable>::getLastNode(BinaryHeapNode* t)
{
	// 需要使用层级遍历
}
