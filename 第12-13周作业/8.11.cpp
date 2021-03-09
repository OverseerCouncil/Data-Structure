#include<iostream>
#include<stack>
#include<vector>

using namespace std;

const int DefaultVertices = 30;

template<class T>
struct Edge
{
	int dest;
	Edge<T>* link;
	Edge() {};
	Edge(int num) :dest(num), link(NULL) {};
	bool operator != (Edge<T>& R)const
	{
		return (dest != R.dest) ? true : false;
	}
};

template<class T>
struct Vertex
{
	T data;
	Edge<T>* adj;
};

template<class T>
class GraphL
{
private:
	int maxVertices;
	int numEdges;
	int numVertices;
	Vertex<T>* NodeTable;
	int getVertexPos(const T vertex)
	{
		for (int i = 0; i < numVertices; i++)
		{
			if (NodeTable[i].data == vertex)
			{
				return i;
			}
		}
		return -1;
	}
public:
	GraphL(int sz = DefaultVertices);
	~GraphL();
	T getValue(int i)
	{
		return (i >= 0 && i < numVertices) ? NodeTable[i].data : 0;
	}
	bool GraphEmpty()const
	{
		if (numEdges == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool GraphFull()const
	{
		if (numVertices == maxVertices || numEdges == maxVertices * (maxVertices - 1) / 2)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	int NumberOfVertices()
	{
		return numVertices;
	}
	int NumberOfEdges()
	{
		return numEdges;
	}
	bool insertVertex(const T& vertex);
	bool insertEdge(int v1, int v2);
	int getFirstNeighbor(int v);
	int getNextNeighbor(int v, int w);
	bool Input();
	bool Output();
	void DFS();
};

template<class T>
GraphL<T>::GraphL(int sz)
{
	maxVertices = sz;
	numVertices = numEdges = 0;
	NodeTable = new Vertex<T>[maxVertices];
	for (int i = 0; i < maxVertices; i++)
	{
		NodeTable[i].adj = NULL;
	}
}

template<class T>
GraphL<T>::~GraphL()
{
	for (int i = 0; i < numVertices; i++)
	{
		Edge<T>* p = NodeTable[i].adj;
		while (p != NULL)
		{
			NodeTable[i].adj = p->link;
			delete p;
			p = NodeTable[i].adj;
		}
	}
	delete[]NodeTable;
}

template<class T>
bool GraphL<T>::insertVertex(const T& vertex)
{
	if (numVertices == maxVertices)
	{
		return false;
	}
	NodeTable[numVertices].data = vertex;
	numVertices++;
	return true;
}

template<class T>
bool GraphL<T>::insertEdge(int v1, int v2)
{
	if (v1 >= 0 && v1 < numVertices && v2 >= 0 && v2 < numVertices)
	{
		Edge<T>* q, * p = NodeTable[v1].adj;
		while (p != NULL && p->dest != v2)
		{
			p = p->link;
		}
		if (p != NULL)
		{
			return false;
		}
		p = new Edge<T>;
		q = new Edge<T>;
		p->dest = v2;
		p->link = NodeTable[v1].adj;
		NodeTable[v1].adj = p;
		numEdges++;
		return true;
	}
}

template<class T>
int GraphL<T>::getFirstNeighbor(int v)
{
	if (v != -1)
	{
		Edge<T>* p = NodeTable[v].adj;
		if (p != NULL)
		{
			return p->dest;
		}
	}
	return -1;
}

template<class T>
int GraphL<T>::getNextNeighbor(int v, int w)
{
	if (v != -1)
	{
		Edge<T>* p = NodeTable[v].adj;
		while (p != NULL && p->dest != w)
		{
			p = p->link;
		}
		if (p != NULL && p->link != NULL)
		{
			return p->link->dest;
		}
	}
	return -1;
}

template<class T>
bool GraphL<T>::Input()
{
	int i, j, k, m, n;
	T e1, e2;
	cout << "输入顶点数和边数" << endl;
	cin >> n >> m;
	for (i = 0; i < n; i++)
	{
		cout << "顶点" << i;
		cin >> e1;
		insertVertex(e1);
	}
	i = 0;
	while (i < m)
	{
		cout << "边" << i;
		cin >> e1 >> e2;
		j = getVertexPos(e1);
		k = getVertexPos(e2);
		if (j == -1 || k == -1)
		{
			cout << "信息有误，重新输入！" << endl;
		}
		else
		{
			insertEdge(j, k);
			i++;
		}
	}
	return true;
}

template<class T>
bool GraphL<T>::Output()
{
	int i, j, m, n;
	T e1, e2;
	n = NumberOfVertices();
	m = NumberOfEdges();
	cout << n << "," << m << endl;
	for (i = 0; i < n; i++)
	{
		j = getFirstNeighbor(i);
		while (j != -1)
		{
			e1 = getValue(i);
			e2 = getValue(j);
			cout << "(" << e1 << "," << e2 << ")" << endl;
			j = getNextNeighbor(i, j);
		}
	}
	return true;
}

template<class T>
void GraphL<T>::DFS()
{
	vector<int> visited(numVertices, 0);
	stack<int> s;
	int tempw, temp;
	s.push(0);
	vector<int> w(numVertices, 0);
	for (int i = 0; i < numVertices; i++)
	{
		w[i] = getFirstNeighbor(i);
	}
	while (!s.empty())
	{
		if (visited[s.top()] != 1)
		{
			cout << NodeTable[s.top()].data << " ";
			visited[s.top()] = 1;
		}
		while (w[s.top()] != -1)
		{
			if (visited[w[s.top()]] != 1)
			{
				cout << NodeTable[w[s.top()]].data << " ";
				visited[w[s.top()]] = 1;
				s.push(w[s.top()]);
				break;
			}
			temp = s.top();
			tempw = getNextNeighbor(s.top(), w[s.top()]);
			w[temp] = tempw;
		}
		if (w[s.top()] == -1)
		{
			s.pop();
		}
	}
	cout << endl;
}

int main()
{
	GraphL<char> G;
	G.Input();
	G.DFS();
	G.Output();
}