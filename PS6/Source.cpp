#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

map<int, map<int, double>> edges;

int main()
{
	//loop it
	int v;
	cin >> v;

	int e;
	cin >> e;

	if (v == 0 && e == 0)
	{
		return 0;
	}

	edges = map<int, map<int, double>>();
	for (int i = 0; i < e; i++)
	{
		int v1;
		cin >> v1;

		int v2;
		cin >> v2;

		double f;
		cin >> f;

		edges[v1][v2] = f;
		edges[v2][v1] = f;
	}
	
	findPath(v);
}

void findPath(int v)
{
	//setup
	vector<double> size(v, 0);
	vector<int> prev(v, v + 1);
	
	size[0] = 1;

	priority_queue<pair<double, int>> pq;
	pq.push(pair<double, int>(1, 0));

	while (!pq.empty())
	{
		int u = pq.top().second;
		pq.pop();

		for (auto& v : edges[u])
		{
			double w = edges[u][v.first];
			if (size[v.first] < size[u] * w)
			{
				size[v.first] = size[u] * w;
				prev[v.first] = u;
				pq.push(v.first); //this won't really work
			}
		}

	}
}