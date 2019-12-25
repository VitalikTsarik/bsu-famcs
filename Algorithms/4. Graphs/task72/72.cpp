#include <fstream>
#include <vector>
#include <queue>

using namespace std;

int n, m;

struct node
{
	int vertex;
	int length;

	node(int vertex, int length) : vertex(vertex), length(length) {}
};

struct cmp
{
	bool operator()(const pair<unsigned, int>& l, const pair<unsigned, int>& r) const
	{
		return l.first > r.first;
	}
};

unsigned Dijkstra(const vector<vector<node>>& adj_list, int start, int dist)
{
	vector<bool> visited(n, false);
	vector<unsigned> distance(n, UINT_MAX);
	distance[start] = 0;
	priority_queue <pair<unsigned, int>, vector<pair<unsigned, int>>, cmp>pq;

	pq.emplace(distance[start], start);

	while (!pq.empty())
	{
		pair<unsigned, int> cur = pq.top();
		if (cur.second == dist)
			break;
		pq.pop();
		visited[cur.second] = true;

		for (node node : adj_list[cur.second])
			if (!visited[node.vertex] && cur.first + node.length < distance[node.vertex])
			{
				distance[node.vertex] = cur.first + node.length;
				pq.emplace(distance[node.vertex], node.vertex);
			}
	}

	return distance[dist];
}

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	fin >> n >> m;
	vector<vector<node>>  adj_list(n);
	int vert1, vert2, length;

	for (int i = 0; i < m; ++i)
	{
		fin >> vert1 >> vert2 >> length;
		adj_list[vert1 - 1].emplace_back(vert2 - 1, length);
		adj_list[vert2 - 1].emplace_back(vert1 - 1, length);
	}

	fout << Dijkstra(adj_list, 0, n - 1);
	return 0;
}
