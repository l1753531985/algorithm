#include <iostream>

using namespace std;

template <typename Object>
struct Node {
	Node* next;
	Object data;
};

template <typename Object>
class List {
private:
	Node<Object>* ListHead;
public:
	List(Node<Object>* head = nullptr) : ListHead{head} {}
	~List() { delete ListHead; }
};

int main()
{
	List<int> l;
	return 0;
}
