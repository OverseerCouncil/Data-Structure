#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void Input(vector<vector<int>>& graph)
{
	int temp;
	int VecN = 0;
	cout << "Enter the Vertex Number" << endl;
	cin >> VecN;
	graph.resize(VecN);
	for (int i = 0; i < VecN; i++)
	{
		do
		{
			cin >> temp;
			graph[i].push_back(temp);
		} while (cin.get() != '\n');
	}
}

bool DFS(vector<vector<int>>& graph, vector<int>& colors, int color, int node)
{
	if (colors[node] != -1)
	{
		return colors[node] == color;
	}
	colors[node] = color;
	for (auto next : graph[node])
	{
		if (!DFS(graph, colors, 1 - color, next))
		{
			return false;
		}
	}
	return true;
}

bool isBipartite_dfs(vector<vector<int>>& graph)
{
	int n = graph.size();
	vector<int> colors(n, -1);
	for (int i = 0; i < n; ++i)
	{
		if (colors[i] == -1 && !DFS(graph, colors, 0, i))
		{
			return false;
		}
	}
	return true;
}

bool BFS(vector<vector<int>>& graph, vector<int>& colors, int color, int node)
{
	queue<int> q;
	q.push(node);
	colors[node] = color;
	while (!q.empty())
	{
		int i = q.front(), c = colors[i];
		q.pop();
		for (auto next : graph[i])
		{
			if (colors[next] == -1)
			{
				q.push(next);
				colors[next] = 1 - colors[i];
			}
			else
			{
				if (colors[next] != 1 - colors[i])
				{
					return false;
				}
			}
		}
	}
	return true;
}

bool isBipartite_bfs(vector<vector<int>>& graph)
{
	int n = graph.size();
	vector<int> colors(n, -1);
	for (int i = 0; i < n; ++i)
	{
		if (colors[i] == -1)
		{
			if (!BFS(graph, colors, 0, i))
			{
				return false;
			}
		}
	}
	return true;
}

int main()
{
	vector<vector<int>> graph;
	Input(graph);
	if (isBipartite_dfs(graph))
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}
	if (isBipartite_bfs(graph))
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}
}