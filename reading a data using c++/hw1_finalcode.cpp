/*
Name: Prashil Soni
Student_Number: S00375453
CSCI 6970: SPT Obj Ori Prog C++ B 
HOMEWORK:1
06/17/2020
*/

#include <iostream>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
	const char separator = ' ';
	const int width = 35;

	string line, city;
	string word = "";
	bool name = false;
	float num, sum;

	ifstream fin;
	ofstream fout;
	fin.open("tempData.txt");
	fout.open("output.txt");

	while (fin && fout)
	{

		// Read a Line from File
		getline(fin, line);
		istringstream ss(line);

		sum = 0;
		name = false;

		// Traverse through all words
		while (ss)
		{
			// Read a word
			string word;
			ss >> word;

			if (name == true)
			{
				stringstream geek(word);

				//convert word to integer
				int x = 0;
				geek >> x;

				//num = atoi(word);
				sum = sum + x;
			}
			else
			{
				city = word;
			}

			name = true;

			// While there is more to read
		}

		if (city != "")
		{
			sum = sum / 12;
			string c = "   City:  " + city;
			fout << std::left << setw(width) << c << "  Average Temp:  " << sum << endl;
		}

		// Print line in Console
		//cout << line << endl;
		//cout<<sum;
	}

	// close the opened file.
	fin.close();
	fout.close();

	fin.open("output.txt");

	while (fin)
	{
		getline(fin, line);
		istringstream ss(line);
		cout << line << endl;
	}
}