#include <iostream>
#include <string>
#include <map>
#include <vector>
//#include <pair>

using namespace std;

map<string, map<string, int>> Map;
vector<string> sorted;

int main()
{
	int cities;
	cin >> cities;

	map<string, int> tolls;

	for (int i = 0; i < cities; i++)
	{
		string city;
		cin >> city;

		int toll;
		cin >> toll;

		tolls[city] = toll;
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
	}

	
	//sorted = topoSort();

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
			topoSort(start);

			//reverseVec(sorted);
		}
	}


}

void topoSort(string startCity)
{
	sorted = vector<string>();
	depthFirstSearch(startCity, 0);
}

void depthFirstSearch(string startCity, int value)
{
	//this iterates through the map
	for (map<string, int>::iterator it = Map[startCity].begin(); it != Map[startCity].end(); it++)
	{
		depthFirstSearch(it->first, value++);
	}

	sorted.push_back(startCity);
}

vector<string> reverseVec(vector<string> vec)
{
	vector<string> temp(vec.size());

	for (int i = 0; i < vec.size(); i++)
	{
		temp[i] = vec[vec.size() - i - 1];
	}

	return temp;
}