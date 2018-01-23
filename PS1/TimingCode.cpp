#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <algorithm>

typedef std::chrono::high_resolution_clock Clock;

using namespace std;

double timeToAnaga(int, int);
vector<string> randomWords(int, int);
void doAnaga(vector<string>, int, int);
string insertionSort(string);
vector<string> insertionSort2(vector<string>);

double ELAPSED = 5000;

int main()
{
	cout << "Words\tTime (msec)\tDelta (msec)" << endl;

	double previousTime = 0;
	for (int i = 2; i <= 1024; i *= 2)
	{
		double time = timeToAnaga(i, 5);

		cout << i << '\t' << time;

		if (i > 2)
		{
			cout << '\t' << (time - previousTime);
		}
		
		cout << endl;
		
		previousTime = time;
	}

	cout << "Letters\tTime (msec)\tDelta (msec)" << endl;

	previousTime = 0;
	for (int i = 2; i <= 1024; i *= 2)
	{
		double time = timeToAnaga(2000, i);

		cout << i << '\t' << time;

		if (i > 2)
		{
			cout << '\t' << (time - previousTime);
		}

		cout << endl;

		previousTime = time;
	}
}

double timeToAnaga(int n, int k)
{
	double elapsed = 0;
	double repetitions = 1;

	do
	{
		repetitions *= 2;
		auto time1 = Clock::now();
		for (long i = 0; i < repetitions; i++)
		{
			vector<string> words = randomWords(n, k);
			doAnaga(words, n, k);
		}
		auto time2 = Clock::now();
		elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(time2 - time1).count();
	} while (elapsed < ELAPSED);
	double totalAverage = elapsed / repetitions;

	elapsed = 0;
	repetitions = 1;
	do
	{
		repetitions *= 2;
		auto time1 = Clock::now();
		for (long i = 0; i < repetitions; i++)
		{
			vector<string> words = randomWords(n, k);
			//doAnaga(words, n, k);
		}
		auto time2 = Clock::now();
		elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(time2 - time1).count();
	} while (elapsed < ELAPSED);
	double overheadAverage = elapsed / repetitions;

	return totalAverage - overheadAverage;
}

vector<string> randomWords(int words, int letters)
{
	vector<string> wordlist(words);

	for (int i = 0; i < words; i++)
	{
		string temp;
		for (int j = 0; j < letters; j++)
		{
			temp += (char)(rand() % 26 + 97);
		}
		wordlist[i] = temp;
	}

	return wordlist;
}

void doAnaga(vector<string> words, int n, int k)
{
	vector<char> chars;
	for (int i = 0; i < n; i++)
	{
		chars = vector<char>(words[i].begin(), words[i].end());
		//sorts letters in word
		sort(chars.begin(), chars.end());
	}

	//words = insertionSort2(words);
	sort(words.begin(), words.end());

	int dupes = 0;
	//compares words
	for (int i = 0; i < words.size() - 1; i++)
	{
		if (words[i].compare(words[i + 1]) == 0)
		{
			dupes += 2;
			i++;
		}
	}

	int nonDupes = words.size() - dupes;
}

string insertionSort(string vec)
{
	int i = 1;

	while (i < vec.size())
	{
		char temp = vec[i];
		int j = i - 1;
		while (j >= 0 && vec[j] > temp)
		{
			vec[j + 1] = vec[j];
			j--;
		}
		vec[j + 1] = temp;
		i++;
	}

	return vec;
}

vector<string> insertionSort2(vector<string> vec)
{
	int i = 1;

	while (i < vec.size())
	{
		string temp = vec[i];
		int j = i - 1;
		while (j >= 0 && vec[j].compare(temp) > 0)
		{
			vec[j + 1] = vec[j];
			j--;
		}
		vec[j + 1] = temp;
		i++;
	}

	return vec;
}


