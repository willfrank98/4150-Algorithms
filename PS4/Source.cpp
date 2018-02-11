#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

map<string, map<string, int>> Map;
vector<string> sorted;
map<string, int> tolls;	//doubles as a list of all cities

void topoSort(map<string, int>);
int cheapestPath(string start, string dest);

int main()
{
	int cities;
	cin >> cities;

	map<string, int> inputs;

	for (int i = 0; i < cities; i++)
	{
		string city;
		cin >> city;

		int toll;
		cin >> toll;

		tolls[city] = toll;
		inputs[city] = 0;
	}

	for (auto& it : tolls)
	{
		for (auto& it2 : tolls)
		{
			Map[it.first][it2.first] = INT32_MAX;
		}
	}

	int highways;
	cin >> highways;

	for (int i = 0; i < highways; i++)
	{
		string start;
		cin >> start;

		string end;
		cin >> end;

		Map[start][end] = tolls[end];
		inputs[end]++;
	}
	
	topoSort(inputs);

	int trips;
	cin >> trips;

	for (int i = 0; i < trips; i++)
	{
		string start;
		cin >> start;

		string dest;
		cin >> dest;

		if (start == dest)
		{
			cout << "0" << endl;
		}
		else
		{
			int cost = cheapestPath(start, dest);

			if (cost == -1 || cost == INT32_MAX)
			{
				cout << "NO" << endl;
			}
			else
			{
				cout << cost << endl;
			}
		}
	}


}

void topoSort(map<string, int> inputs)
{
	sorted = vector<string>();

	while (inputs.size() > 0)
	{
		vector<string> toErase;
		for (auto& it : inputs)
		{
			if (it.second == 0)
			{
				string source = it.first;
				sorted.push_back(source);

				toErase.push_back(source);

			}
		}

		for (int i = 0; i < toErase.size(); i++)
		{
			string source = toErase[i];
			//update inputs to reflect new sources
			for (auto& it : Map[source])
			{
				string dest = it.first;

				//if there is a highway from source to dest
				if (Map[source][dest] != INT32_MAX)
				{
					inputs[dest]--;
				}
			}

			inputs.erase(source);
		}
	}

	//find source
	//add to sorted
	//delete
	//repeat until inputs.size() == 0
}

int cheapestPath(string start, string dest)
{
	//cost to get to [something] from start
	map<string, int> cost;

	for (auto& it : tolls)
	{
		cost[it.first] = INT32_MAX;
	}

	cost[start] = 0;

	int i;
	for (i = 0; i < sorted.size(); i++)
	{
		if (sorted[i] == dest)
		{
			return -1;
		}
		if (sorted[i] == start)
		{
			break;
		}
	}

	for (i += 1;i < sorted.size(); i++)
	{
		string tempDest = sorted[i];

		int tempCost = INT32_MAX;
		for (auto& it : tolls)
		{
			string tempStart = it.first;
			if (Map[tempStart][tempDest] != INT32_MAX) //if there is a highway here
			{
				if (cost[tempStart] < tempCost)
				{
					tempCost = cost[tempStart] + Map[tempStart][tempDest];
				}
			}
		}

		if (tempDest == dest)
		{
			return tempCost;
		}
		else
		{
			cost[tempDest] = tempCost;
		}
	}

	return -1;
}