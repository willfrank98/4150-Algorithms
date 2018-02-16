#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

string generateReport(string student);

map<string, map<string, bool>> friends;
map<string, bool> knows;

int main()
{
	int students;
	cin >> students;

	vector<string> names(students);
	for (int i = 0; i < students; i++)
	{
		string name;
		cin >> name;
		names[i] = name;
		knows[name] = false;
	}

	int friendPairs;
	cin >> friendPairs;

	for (int i = 0; i < friendPairs; i++)
	{
		string f1;
		cin >> f1;
		string f2;
		cin >> f2;

		friends[f1][f2] = true;
		friends[f2][f1] = true; //friendship goes both ways
	}

	int reports;
	cin >> reports;

	for (int i = 0; i < reports; i++)
	{
		string student;
		cin >> student;

		string report = generateReport(student);
		cout << report << endl;
	}
}

string generateReport(string student, vector<string> studentsVec)
{
	string report = student + " ";

	vector<string> students;
	students.push_back(student);
	while (students.size() > 0)
	{
		vector<string> newStudents;
		for (string name : students)
		{
			for (auto& f : friends[name])
			{
				if (!knows[f.first])
				{
					newStudents.push_back(f.first);
					knows[f.first] = true;
				}
				
			}
		}

		//alphabetizes
		sort(newStudents.begin(), newStudents.end());
		//adds to report
		for (string name : newStudents)
		{
			report += name + " ";
		}

		students = newStudents;
	}

	for (auto& name : knows)
	{
		if (name.second)
		{

		}
	}

	return report;
}

void knowsReset()
{
	for (auto& student : knows)
	{
		student.second = false;
	}
}