#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

pair<int, int> findMajority(vector<pair<int, int>> points);
bool inGalaxy(pair<int, int> o, pair<int, int> p);

double diameter;

int main()
{
	cin >> diameter;

	double stars;
	cin >> stars;

	vector<pair<int, int>> starList(stars);
	for (int i = 0; i < stars; i++)
	{
		double x;
		double y;
		cin >> x;
		cin >> y;

		pair<int, int> p(x, y);
		starList[i] = p;
	}

	pair<int, int> majority = findMajority(starList);

	if (majority.first == -1 && majority.second == -1)
	{
		cout << "NO";
	}
	else
	{
		int number = 0;
		for (int i = 0; i < starList.size(); i++)
		{
			if (inGalaxy(majority, starList[i]))
			{
				number++;
			}
		}

		cout << number;
	}

}



pair<int, int> findMajority(vector<pair<int, int>> points)
{
	int size = points.size();
	if (size == 0)
	{
		return pair<int, int>(-1, -1);
	}
	else if (size == 1)
	{
		return points[0];
	}

	vector<pair<int, int>> kept;

	for (int i = 1; i < size; i += 2)
	{
		if (inGalaxy(points[i - 1], points[i]))
		{
			kept.push_back(points[i]);
		}
	}

	pair<int, int> leftover;
	if (size % 2 == 1)
	{
		leftover = points.back();
	}

	pair<int, int> maj = findMajority(kept);

	//if no majority
	if (maj.first == -1 && maj.second == -1)
	{
		if (size % 2 == 1)
		{
			int numLeftover = 0;
			for (int i = 0; i < size; i++)
			{
				if (inGalaxy(leftover, points[i]))
				{
					numLeftover++;
				}
			}
			if (numLeftover > size / 2)
			{
				return leftover;
			}
		}
		
		return pair<int, int>(-1, -1);
		
	}
	else
	{
		int numMaj = 0;
		for (int i = 0; i < size; i++)
		{
			if (inGalaxy(leftover, points[i]))
			{
				numMaj++;
			}
		}
		if (numMaj > size / 2)
		{
			return maj;
		}
		else
		{
			return pair<int, int>(-1, -1);
		}
	}
	
}

bool inGalaxy(pair<int, int> o, pair<int, int> p)
{
	return ((pow((o.first - p.first), 2) + pow((o.second - p.second), 2)) <= pow(diameter, 2));
}