/*
PRASHIL SONI – S00375453
CSCI 6970, HW3
Date: 09/27/2020
*/ 

#include <iostream>
#include <stack>
#include <fstream>
using namespace std;
bool check(string str)
{
	stack<char> myStack; //stack object
	char temp;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '(' || str[i] == '[' || str[i] == '{') //checking if there is any starting bracket and then pushing into stack
		{
			myStack.push(str[i]);
			continue;
		}
		if (myStack.size() == 0)
			return false;
		if (str[i] == ')') //checking if there is a round ending bracket
		{
			temp = myStack.top();
			myStack.pop();
			if (temp == '{' || temp == '[')
				return false;
		}
		else if (str[i] == '}') //checking if there is a curly ending bracket
		{
			temp = myStack.top();
			myStack.pop();
			if (temp == '(' || temp == '[')
				return false;
		}
		else if (str[i] == ']') //checking if there is a square ending bracket
		{
			temp = myStack.top();
			myStack.pop();
			if (temp == '(' || temp == '{')
				return false;
		}
	}
	return (myStack.empty());
}

int main()
{

	ifstream fin;
	fin.open("input.txt"); //opening the file input.txt
	string input;
	fin >> input;
	while (fin)
	{
		if (check(input)) //if the expression is valid
			cout << "The expression is balanced" << endl;
		else
			cout << "The expression is not balanced" << endl;
		fin >> input;
	}
	system("PAUSE");
}