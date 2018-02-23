#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>

using namespace std;

double findPath(int v);

vector<vector<pair<int, double>>> edges;

int main()
{
	cout.setf(ios::fixed, ios::floatfield);
	cout.precision(4); //sets output to 4 decimal places

	while (1 < 2) //is this bad practice?
	{
		int v;
		cin >> v;

		int e;
		cin >> e;

		if (v == 0 && e == 0)
		{
			return 0;
		}

		edges = vector<vector<pair<int, double>>>(v, vector<pair<int, double>>());
		//vector<vector<pair<int, double>>> edges2(v, vector<pair<int, double>>(v));
		
		for (int i = 0; i < e; i++)
		{
			int v1;
			cin >> v1;

			int v2;
			cin >> v2;

			double f;
			cin >> f;

			//undirected edges
			edges[v1].push_back(pair<int, double>(v2, f));
			edges[v2].push_back(pair<int, double>(v1, f));
		}

		cout << findPath(v) << endl;
	}
	
}

double findPath(int v)
{
	//setup
	vector<double> size(v, 0);
	vector<int> prev(v, v + 1);
	
	size[0] = 1;

	priority_queue<pair<double, int>> pq;
	pq.push(pair<double, int>(1.0, 0));

	while (!pq.empty())
	{
		int u = pq.top().second;
		pq.pop();

		for (pair<int, double>& v : edges[u])
		{
			double w = v.second;
			if (size[v.first] < size[u] * w)
			{
				size[v.first] = size[u] * w;
				prev[v.first] = u;
				pq.push(pair<double, int>(size[v.first], v.first));
			}
		}
	}

	return size[v - 1];
}