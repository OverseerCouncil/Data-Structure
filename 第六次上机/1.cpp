#include<iostream>

using namespace std;

template<class T>
struct LinkNode
{
	T data;
	LinkNode<T>* link;
	LinkNode(LinkNode<T>* ptr = NULL) { link = ptr; }
	LinkNode(const T& item, LinkNode<T>* ptr = NULL) { data = item; link = ptr; }
};


template<class T>
class LinkQueue
{
private:
	LinkNode<T>* front;
	LinkNode<T>* rear;
public:
	LinkQueue() :front(NULL), rear(NULL) {}		//构造函数，建立空队列
	~LinkQueue() { makeEmpty(); }		//析构函数
	bool EnQueue(const T& x);		//入队
	bool DeQueue(T& x);		//出队
	bool getFront(T& x)const;		//读取队头元素
	bool IsEmpty()const { return(front == NULL) ? true : false; }
	int getSize()const;		//求元素个数
	void makeEmpty();		//清空队列
};

template<class T>
void LinkQueue<T>::makeEmpty()
{
	LinkNode<T>* p;
	while (front != NULL)
	{
		p = front;
		front = front->link;
		delete p;
	}
}

template<class T>
bool LinkQueue<T>::EnQueue(const T& x)
{
	if (front == NULL)
	{
		front = rear = new LinkNode<T>(x);
		if (front == NULL) { return false; }
	}
	else
	{
		rear->link = new LinkNode<T>(x);
		if (rear->link == NULL) { return false; }
		rear = rear->link;
	}
	return true;
}

template<class T>
bool LinkQueue<T>::DeQueue(T& x)
{
	if (IsEmpty() == true) { return false; }
	LinkNode<T>* p = front;
	x = p->data;
	front = front->link;
	delete p;
	return true;
}
template<class T>
bool LinkQueue<T>::getFront(T& x)const
{
	if (IsEmpty() == true) { return false; }
	x = front->data;
	return true;
}

template<class T>
int LinkQueue<T>::getSize()const
{
	LinkNode<T>* p = front;
	int k = 0;
	while (p != NULL)
	{
		p = p->link;
		k++;
	}
	return k;
}

int main()
{
	LinkQueue<int> OPR;
	int n;
	int temp;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		OPR.EnQueue(i + 1);
	}
	while (OPR.getSize() >= 2)
	{
		OPR.DeQueue(temp);
		cout << temp << " ";
		OPR.DeQueue(temp);
		OPR.EnQueue(temp);
	}
	OPR.DeQueue(temp);
	cout << temp << endl;
	system("pause");
}