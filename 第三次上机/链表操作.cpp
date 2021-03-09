#include<iostream>

using namespace std;

template<class T>
struct LinkNode
{
	T data;
	LinkNode<T>* link;
	LinkNode(LinkNode<T>* ptr = NULL) { link = ptr; }
	LinkNode(const T& item, LinkNode<T>* ptr = NULL)
	{
		data = item;
		link = ptr;
	}
};
/*struct定义表结点*/

template<class T>
class List
{
private:
	LinkNode<T>* first;/*辅助表头结点*/
public:
	List() { first = new LinkNode<T>; }
	List(const T& x) { first = new LinkNode<T>(x); }
	~List() { makeEmpty(); }
	void makeEmpty();/*置空表*/
	bool add(T x);/*表尾添加元素*/
	bool find(T x);/* 寻找指定值结点*/
	bool remove(T x);/*删除指定值结点*/
	void printList();/*输出链表序列*/
};


template<class T>
void List<T>::makeEmpty()
{
	LinkNode<T>* q;
	while (first->link != NULL)
	{
		q = first->link;
		first->link = q->link;
		delete q;
	}
};

template<class T>
bool List<T>::add(T x)
{
	LinkNode<T>* current = first;
	while (current->link != NULL)
	{
		current = current->link;
	}
	current->link = new LinkNode<T>(x);
	return true;
}

template<class T>
bool List<T>::remove(T x)
{
	LinkNode<T>* front = first;
	LinkNode<T>* current = first->link;
	while (current != NULL)
	{
		if (current->data == x)
		{
			front->link = current->link;
			delete current;
			return true;
		}
		else
		{
			front = current;
			current = current->link;
		}
	}
	return false;
}

template<class T>
bool List<T>::find(T x)
{
	if (i < 0) { return NULL; }
	LinkNode<T>* current = first;
	while (current != NULL)
	{
		current = current->link;
		if (current->data == x)
		{
			return true;
		}
	}
	return false;
}

template<class T>
void List<T>::printList()
{
	LinkNode<T>* current = first->link;
	while (current != NULL)
	{
		cout << current->data << " ";
		current = current->link;
	}
	cout << endl;
}