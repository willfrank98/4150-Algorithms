#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int people;
	cin >> people;

	int time;
	cin >> time;

	vector<pair<int, int>> patrons;
	for (int i = 0; i < people; i++)
	{
		int c;
		int t;
		cin >> c >> t;

		patrons.push_back(pair<int, int>(c, t));
	}

	int money = 0;
	for (int i = time - 1; i >= 0; i--)
	{
		int temp = 0;
		int pos = -1;
		for (int j = 0; j < patrons.size(); j++)
		{
			if (patrons[j].first > temp && patrons[j].second >= i)
			{
				temp = patrons[j].first;
				pos = j;
			}
		}
		if (pos != -1)
		{
			money += temp;
			patrons.erase(patrons.begin() + pos);
		}
		
	}

	cout << money;
}