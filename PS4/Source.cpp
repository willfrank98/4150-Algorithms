#include <iostream>
#include <string>
#include <map>
#include <vector>
//#include <pair>

using namespace std;

int main()
{
	int cities;
	cin >> cities;

	map<string, map<string, int>> Map;
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

	topoSort();

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
			cout << findValue() << endl;
		}
	}


}

void topoSort()
{

}

void depthFirstSearch(string startCity)
{

}

int findValue()
{

}