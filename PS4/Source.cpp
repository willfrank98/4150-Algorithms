#include <iostream>
#include <string>
#include <map>
#include <vector>
//#include <pair>

using namespace std;

map<string, map<string, int>> Map;
vector<string> sorted;

void topoSort(map<string, int>);
int cheapestPath(string start, string dest);

int main()
{
	int cities;
	cin >> cities;

	map<string, int> tolls;

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
			
		}
	}


}

void topoSort(map<string, int> inputs)
{
	sorted = vector<string>();

	while (inputs.size() > 0)
	{
		vector<string> toErase;
		for (map<string, int>::iterator it = inputs.begin(); it != inputs.end(); it++)
		{
			if (it->second == 0)
			{
				string source = it->first;
				sorted.push_back(source);

				inputs.erase(source);
				toErase.push_back(source);

			}
		}

		for (int i = 0; i < toErase.size(); i++)
		{
			string source = toErase[i];
			//update inputs to reflect new sources
			for (map<string, int>::iterator it = Map[source].begin(); it != Map[source].end(); it++)
			{
				string dest = it->first;

				//if there is a highway from source to dest
				if (Map[source][dest] > 0)
				{
					inputs[dest]--;
				}
			}
		}
		
	}

	//find source
	//add to sorted
	//delete
	//repeat until inputs.size() == 0
}

int cheapestPath(string start, string dest)
{
	//cost to get to [] from start
	map<string, int> cost;

	int i;
	for (i = 0; i < sorted.size(); i++)
	{
		if (sorted[i] == start)
		{
			break;
		}
	}

	for (i += 1;i < sorted.size(); i++)
	{
		string tempDest = sorted[i];


	}
}