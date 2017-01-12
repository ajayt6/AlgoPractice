/*
This is incomplete
*/
#include<iostream>
#include<vector>
using namespace std;

class State
{
public:

	string value;
	int times;
	State *next;
	vector<pair<char, char>> rangeVector;

	State(string entry)
	{
		value = entry;
		times = 0;
		next = NULL;
	}

	void match()
	{

	}
};

bool match(string candidate, State *head)
{

	return false;
}

//Give a regex here
// (a-z)+8(3-6)*2

int main()
{
	State *head = NULL;

	getchar();
	return 0;
}