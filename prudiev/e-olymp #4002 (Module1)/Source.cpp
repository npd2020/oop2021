#include <iostream>
#include <vector>
using namespace std;

int main() 
{
	bool ans = true;

	int n_students, n_pairs;
	cin >> n_students >> n_pairs;

	vector<int>* students = new vector<int>[n_students];	// students matrix

	int student1tag, student2tag;
	for (int i = 0; i < n_pairs; i++)						
	{
		cin >> student1tag >> student2tag;
		student1tag--;
		student2tag--;
		students[student1tag].push_back(student2tag);		// stores info into matrix
		students[student2tag].push_back(student1tag);		// symmetrical matrix
	}

	int* groupNumber = new int[n_students];					// tag students' team
	for (int student_index = 0; student_index < n_students; student_index++)
	{
		groupNumber[student_index] = 0;						// no team by default
	}

	for (int student_index = 0; student_index < n_students; student_index++) // fills teams with people
	{

		if (groupNumber[student_index] == 0)				// do only if student has no team
		{

			groupNumber[student_index] = 1;


			for (auto linkedStudent : students[student_index])
			{	
				if (groupNumber[linkedStudent] == 0)
				{
					groupNumber[linkedStudent] = 2;
				}
				else if (groupNumber[linkedStudent] == 1)
				{
					ans = false;
					break;
				}
			}
		}

		else												// check if linked students are in the same team
		{
			for (auto linkedStudent : students[student_index])
			{
				if (groupNumber[linkedStudent] == groupNumber[student_index])
				{
					ans = false;
					break;
				}
			}
		}
	}


	cout << (ans ? "YES" : "NO");
}