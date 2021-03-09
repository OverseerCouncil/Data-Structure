#include <iostream>
#include <cstdlib>

using namespace std;

class List
{
private:
	typedef struct ListNode
	{
		int data;
		ListNode* next;
	};
	ListNode* head, * opr, * end;
	int ListSize;

public:
	List();
	~List();
	void AddNode();
	ListNode* ChangePos(ListNode *head,unsigned int k);
	void Show();
	ListNode* AddressHead();
	void ChangeHead(ListNode *Head);
};

List::List()
{
	head = (ListNode*)malloc(sizeof(ListNode));
	cout << "Please Input the First Number" << endl;
	cin >> head->data;
	opr = head;
	end = head;
	ListSize = 1;
	cout << "The List has been Created." << endl;
}

List::~List()
{
	while (head!= 0)
	{
		opr = head->next;
		delete head;
		head = opr;
	}
	delete head;
	cout << "The List has been Deleted." << endl;
}

void List::AddNode()
{
	end = (ListNode*)malloc(sizeof(ListNode));
	cout << "Please Input the Number" << endl;
	cin >> end->data;
	end->next = 0;
	opr->next = end;
	opr = end;
	ListSize++;
	cout << "The new Node has been added." << endl;
}

List::ListNode* List::ChangePos(ListNode *Head,unsigned int k)
{
	ListNode* Temp;
	unsigned int i=0;
	opr = Head;
	if (opr == 0)
	{
		cout << "Peremeter Error" << endl;
		return Head;
	}
	while (opr != 0 && i < 2)
	{
		opr = opr->next;
		i++;
	}
	if (i == k)
	{
		opr = ChangePos(opr,2);
		while (i-- > 0)
		{
			Temp = Head->next;
			Head->next = opr;
			opr = Head;
			Head = Temp;
		}
		Head = opr;
	}
	return Head;
}

void List::Show()
{
	if (head == 0)
	{
		cout << "There is no List." << endl;
		return;
	}
	opr = head;
	while (opr->next != 0)
	{
		cout << opr->data << "->";
		opr = opr->next;
	}
	cout << opr->data << endl;
	cout << "The List has been shown." << endl;
}

List::ListNode* List::AddressHead()
{
	return head;
}

void List::ChangeHead(ListNode *Head)
{
	head = Head;
}

int main()
{
	List Mylist;
	unsigned int Function;
	unsigned int k;
	while (true)
	{
		cout << "Enter 2 to Add;Enter 3 to Exchange;Enter 4 to show;Enter 5 to Delete;Enter 0 to Exit" << endl;
		cin >> Function;
		switch (Function)
		{
		case 2:
			Mylist.AddNode();
			break;
		case 3:
			Mylist.ChangeHead(Mylist.ChangePos(Mylist.AddressHead(),2));
			break;
		case 4:
			Mylist.Show();
			break;
		case 5:
			Mylist.~List();
			break;
		case 0:
			return 0;
		default:
			cout << "Please Check Your Input" << endl;
			break;
		}
	}

	system("pause");
}
