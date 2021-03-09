#include<iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode():next(NULL){}
	ListNode(int x):val(x),next(NULL){}
};

class List
{
private:
	ListNode* first;
	ListNode* end;
public:
	List() { first = new ListNode; end = first; }
	void Input()
	{
		int NumIn;
		while (cin >> NumIn)
		{
			end->next = new ListNode(NumIn);
			end = end->next;
			if (cin.get() == '\n')
			{
				break;
			}
		}
	}
	ListNode* Partion(ListNode* Begin,ListNode* End)
	{
		int temp;
		ListNode* p = Begin;
		ListNode* q = Begin->next;
		int key = p->val;
		while (q != End)
		{
			if (q->val < key)
			{
				p = p->next;
				temp = p->val;
				p->val = q->val;
				q->val = temp;
			}
			q = q->next;
		}
		temp = Begin->val;
		Begin->val = p->val;
		p->val = temp;
		return p;
	}
	void Sort(ListNode* Begin, ListNode* End)
	{
		if (Begin != End)
		{
			ListNode* mid = Partion(Begin, End);
			Sort(Begin, mid);
			Sort(mid->next, End);
		}
	}
	void Kill()
	{
		ListNode* pre = first;
		ListNode* cur = first->next;
		Sort(first->next, end);
		while (pre->next)
		{
			cur = pre->next;
			while (cur->next && cur->next->val == cur->val)
			{
				cur = cur->next;
			}
			if (cur != pre->next)
			{
				pre->next = cur->next;
			}
			else
			{
				pre = pre->next;
			}
		}
	}
	void Output()
	{
		ListNode* current = first;
		if (current->next == NULL)
		{
			cerr << "Empty List!" << endl;
			return;
		}
		do
		{
			current = current->next;
			cout << current->val << ' ';
		} while (current->next!=NULL);
	}
};

int main()
{
	List Mylist;
	Mylist.Input();
	Mylist.Kill();
	Mylist.Output();
}