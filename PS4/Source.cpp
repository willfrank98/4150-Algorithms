#include <iostream>
#include <string>
#include <map>

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

	for (int i = 0; i < cities; i++)
	{
		string start;
		cin >> start;

		string end;
		cin >> end;

		Map[start][end] = tolls[end];
	}


}