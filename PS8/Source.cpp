#include <iostream>
#include <vector>
//#include <queue>

using namespace std;

//class mypair
//{
//public:
//	int first;
//	int second;
//
//	mypair(int f, int s) : first(f), second(s)
//	{}
//
//	bool operator < (mypair p) const
//	{
//		if (first < p.first)
//		{
//			return true;
//		}
//		else if (first > p.first)
//		{
//			return false;
//		}
//		else
//		{
//			if (second < p.second)
//			{
//				return true;
//			}
//		}
//
//		return false;
//	}
//
//	bool operator > (mypair p) const
//	{
//		if (first > p.first)
//		{
//			return true;
//		}
//		else if (first < p.first)
//		{
//			return false;
//		}
//		else
//		{
//			if (second > p.second)
//			{
//				return true;
//			}
//		}
//
//		return false;
//	}
//
//	bool operator == (mypair p) const
//	{
//		if (first == p.first && second == p.second)
//		{
//			return true;
//		}
//		else
//		{
//			return false;
//		}
//	}
//};

int main()
{
	int people;
	cin >> people;

	int time;
	cin >> time;

	//priority_queue<mypair> patrons;
	vector<int> money(time, 0);
	for (int i = 0; i < people; i++)
	{
		int c;
		int t;
		cin >> c >> t;

		//patrons.push(mypair(t, c));
	}

	int total = 0;
	for (int i = 0; i < money.size(); i++)
	{
		total += money[i];
	}

	cout << total;

	/*int money = 0;
	for (int i = 0; i < time; i++)
	{
		mypair temp = patrons.top();
		if (temp.first == i)
		{
			money += temp.second;
			patrons.pop();
		}

		while (patrons.size() > 0 && patrons.top().first == i)
		{
			patrons.pop();
		}
	}*/

	//cout << money;
}