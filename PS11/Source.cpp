#include <iostream>
#include <vector>
#include <string>

using namespace std;

int workout(int height, int index);

vector<int> memory;
string output;

int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int M;
		cin >> M;

		vector<int> lengths(M);

		for (int j = 0; j < M; j++)
		{
			int length;

			cin >> length;
			lengths[j] = length;
		}

		memory = vector<int>(M, -1);
		output = "";

		workout(0, 0);

		cout << output;
	}
}

int workout(int height, int index)
{

}