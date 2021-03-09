#include<iostream>
#include<cassert>

using namespace std;

template<class T>
struct LinkNode
{
	T data;
	LinkNode<T>* link;
	LinkNode(LinkNode<T>* ptr = NULL) { link = prt; }
	LinkNode(const T& item, LinkNode<T>* ptr = NULL) { data = item; link = ptr; }
};


template<class T>
class LinkStack
{
private:
	LinkNode<T>* top;
public:
	LinkStack():top(NULL){}		//构造函数，置空栈
	~LinkStack() { makeEmpty(); }		//析构函数
	void Push(const T& x);		//入栈
	bool Pop(T& x);		//出栈
	bool getTop(T& x)const;		//读取栈顶元素
	bool IsEmpty()const { return(top == NULL) ? true : false; }
	int getSize()const;		//求元素个数
	void makeEmpty();		//清空栈内容
};

template<class T>
void LinkStack<T>::makeEmpty()
{
	LinkNode<T>* p;
	while (top != NULL)
	{
		p = top;
		top = top->link;
		delete p;
	}
}

template<class T>
void LinkStack<T>::Push(const T& x)
{
	top = new LinkNode<T>(x, top);
	assert(top != NULL);
}

template<class T>
bool LinkStack<T>::Pop(T& x)
{
	if (IsEmpty() == true) { return false; }
	LinkNode<T>* p = top;
	top = top->link;
	x = p->data;
	delete p;
	return true;
}
template<class T>
bool LinkStack<T>::getTop(T& x)const
{
	if (IsEmpty() == true) { return false; }
	x = top->data;
	return true;
}

template<class T>
int LinkStack<T>::getSize()const
{
	LinkNode<T>* p = top;
	int k = 0;
	while (p != NULL)
	{
		p = p->link;
		k++;
	}
	return k;
}