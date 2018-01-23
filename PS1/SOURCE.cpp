//#include <iostream>
//#include <string>
//#include <vector>
//
//using namespace std;
//
//string insertionSort(vector<char>);
//vector<string> insertionSort2(vector<string>);
//
//int main()
//{
//	int words;
//	cin >> words;
//
//	int letters;
//	cin >> letters;
//
//	vector<string> wordList(words);
//	vector<char> word(letters);
//	//reads in all words
//	for (int i = 0; i < words; i++)
//	{
//		for (int j = 0; j < letters; j++)
//		{
//			cin >> word[j];
//		}
//
//		//sorts letters in word
//		string newWord = insertionSort(word);
//
//		wordList[i] = newWord;
//	}
//
//	wordList = insertionSort2(wordList);
//
//	int dupes = 0;
//	//compares words
//	for (int i = 0; i < wordList.size() - 1; i++)
//	{
//		if (wordList[i].compare(wordList[i + 1]) == 0)
//		{
//			dupes += 2;
//			i++;
//		}
//	}
//
//	int nonDupes = wordList.size() - dupes;
//
//	cout << nonDupes;
//}
//
//string insertionSort(vector<char> vec)
//{
//	int i = 1;
//
//	while (i < vec.size())
//	{
//		char temp = vec[i];
//		int j = i - 1;
//		while (j >= 0 && vec[j] > temp)
//		{
//			vec[j + 1] = vec[j];
//			j--;
//		}
//		vec[j + 1] = temp;
//		i++;
//	}
//
//	string ret = "";
//
//	for (int i = 0; i < vec.size(); i++)
//	{
//		ret += vec[i];
//	}
//
//	return ret;
//}
//
//vector<string> insertionSort2(vector<string> vec)
//{
//	int i = 1;
//
//	while (i < vec.size())
//	{
//		string temp = vec[i];
//		int j = i - 1;
//		while (j >= 0 && vec[j].compare(temp) > 0)
//		{
//			vec[j + 1] = vec[j];
//			j--;
//		}
//		vec[j + 1] = temp;
//		i++;
//	}
//
//	return vec;
//}