#include<iostream>
#include<cstdlib>

using namespace std;

const int defaultSize = 100;

template <class T> class SeqList
{
private:
	T* data;
	int maxSize;
	int last;
	void ReSize(int newSize);
public:
	SeqList(int sz = defaultSize);
	SeqList(SeqList<T>& L);
	~SeqList() { delete[]data; }
	int Size()const { return maxSize; }
	int Length()const { return last + 1; }
	int Search(T& x)const;
	int Locate(int i)const;
	bool getData(int i, T& x)const
	{
		if (i > 0 && i <= last + 1) { x = data[i - 1]; return true; }
		else return false;
	}
	void setData(int i, T& x)
	{
		if (i > 0 && i <= last + 1) { data[i - 1] = x; }
	}
	bool Insert(int i, T& x);
	bool Remove(int i, T& x);
	bool IsEmpty() { return(last == -1) ? true : false; }
	bool IsFull() { return(last == maxSize - 1) ? true : false; }
	void input();
	void output();
};

template <class T>
SeqList<T>::SeqList(int sz)
{
	if (sz > 0)
	{
		maxSize = sz; last = -1;
		data = new T[maxSize];
		if (data == NULL)
		{
			cerr << "存储分配错误！" << endl; exit(1);
		}
	}
}

template <class T>
SeqList<T>::SeqList(SeqList<T>& L)
{
	maxSize = L.Size(); last = L.Length() - 1; T value;
	data = new T[maxSize];
	if (data == NULL)
	{
		cerr << "存储分配错误" << endl; exit(1);
	}
	for (int i = 1; i <= last + 1; i++)
	{
		L.getData(i, value); data[i - 1] = value;
	}
}

template <class T>
void SeqList<T>::ReSize(int newSize)
{
	T* Newarray;
	if (newSize <= 0)
	{
		cerr << "无效的数组大小" << endl; return;
	}
	if (newSize != maxSize)
	{
		Newarray = new T[newSize];
		if (Newarray == NULL)
		{
			cerr << "存储分配错误" << endl; exit(1);
		}
	}
	int n = last + 1;
	T* srcptr = data;
	T* destptr = Newarray;
	while (n--)
	{
		*destptr++ = *srcptr++;
	}
	delete[]data;
	data = Newarray;; maxSize = newSize;
}

template <class T>
int SeqList<T>::Search(T& x)const
{
	for (int i = 0; i <= last; i++)
	{
		if (data[i] == x)return i + 1;
	}
	return 0;
}

template <class T>
int SeqList<T>::Locate(int i)const
{
	if (i >= 1 && i <= last + 1)return i;
	else return 0;
}

template <class T>
bool SeqList<T>::Insert(int i, T& x)
{
	if (last == maxSize - 1)return false;
	if (i<0 || i>last + 1)return false;
	for (int j = last; j >= i; j--)
	{
		data[j + 1] = data[j];
	}
	data[i] = x;
	last++;
	return true;
}

template <class T>
bool SeqList<T>::Remove(int i, T& x)
{
	if (last == -1)return false;
	if (i<1 || i>last + 1)return false;
	x = data[i - 1];
	for (int j = i; j <= last; j++)
	{
		data[j - 1] = data[j];
		last--;
	}
	return true;
}

template <class T>
void SeqList<T>::input()
{
	cout << "开始建立顺序表，请输入末元素位置：";
	while (1)
	{
		cin >> last;
		if (last <= maxSize - 1)break;
		cout << "表元素个数输入有误，范围不能超过" << maxSize - 1 << endl;
	}
	for (int i = 0; i <= last; i++)
	{
		cout << "第" << i + 1 << "个元素" << endl;
		cin >> data[i];
	}
}

template <class T>
void SeqList<T>::output()
{
	cout << "顺序表当前元素最后位置为：" << last << endl;
	for (int i = 0; i <= last; i++)
	{
		cout << "#" << i << ";" << data[i] << endl;
	}
}

int main()
{
	SeqList<int> SL;
	int CprTempS,CprTempT,Temp,CurLength;//1
	SL.input();
	SL.output();
	CurLength = SL.Length();//1
	for (int i = 2; i <= CurLength; i++)//N
	{
		SL.getData(i, CprTempS);//N
		for (int j = 1; j < i; j++)//(N-1)N/2
		{
			SL.getData(j, CprTempT);//(N-1)N/2
			if (CprTempS == CprTempT)//(N-1)N/2
			{
				SL.Remove(i, Temp);
				i--;
				CurLength--;
				break;
			}
		}
	}
	SL.output();
	system("pause");
}