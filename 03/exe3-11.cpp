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
	int size;
	void insert(Node<Object>*, const Object&);
	void erase(Node<Object>*);
	Node<Object>* current;
public:
	List() : size{0} { ListHead = new Node<Object>; ListHead->next = nullptr; current = ListHead->next; }
	~List() 
	{ 
		while (ListHead)
		{
			Node<Object>* tmp = ListHead;
			ListHead = ListHead->next;
			delete tmp;
		}
	}
	void find(const Object&);
	void print(ostream&);
	int getSize() const;
	List<Object>& operator++();
	List<Object> operator++(int);
};

template <typename Object>
void List<Object>::find(const Object& val)
{
	Node<Object>* p = ListHead;
	while (p->next)
	{
		Node<Object>* tmp = p->next;
		if (tmp->data == val) 
		{ erase(p); return; }
		if (tmp->data > val)  
		{ insert(p, val); return; }
		p = tmp;
	}
	//cout << "after find" << endl;
	insert(p, val);
}

template <typename Object>
void List<Object>::insert(Node<Object>* prev, const Object& val)
{
	Node<Object>* q = new Node<Object>;
	q->data = val;
	q->next = prev->next;
	prev->next = q;
	size++;
}

template<typename Object>
void List<Object>::erase(Node<Object>* prev)
{
	Node<Object>* tmp = prev->next;
	prev->next = tmp->next;
	delete tmp;
	size--;
}

template<typename Object>
void List<Object>::print(ostream& os)
{
	Node<Object>* p = ListHead->next;
	while (p) 
	{
		os << p->data << '\t';
		p = p->next;
	}
	os << endl; 
}

template <typename Object>
int List<Object>::getSize() const
{
	return size;
}

template <typename Object>
List<Object>& List<Object>::operator++()
{
	if (ListHead->next && !current) current = nullptr;
	if (!(ListHead->next)) 
	return *this;
}

template <typename Object>
List<Object> operator++(int)
{
	return this
}

int main()
{
	List<int> l;
	cout << "请输入想要查找的数字(存在则删去，不存在则添加):" << endl;
	int num = 0;
	while (cin >> num)
	{
		l.find(num);
		cout << "The count of elements in List is: " << l.getSize() << endl;
		l.print(cout);
	}
	return 0;
}
