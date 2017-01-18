/*
https://leetcode.com/problems/wildcard-matching/
*/

#include<iostream>
#include<string>
using namespace std;

bool isMatch(string s, string p) {
	int i = 0, j = 0,starFlag=0,solidPointer = 0;

	while (i < p.length() && j < s.length())
	{
		switch (p[i])
		{
		case '*':
			i++;
			starFlag = 1;
			break;
		case '?':
			//handle case when starFlag is not set
			if (starFlag == 1)
			{
				j++;
			}
			else
			{
				i++;
				j++;
			}
			break;
		default:
			if (starFlag == 1)
			{
				starFlag = 0;
				while (j < s.length() && s[j] != p[i])
				{
					j++;
				}
				if (j == s.length())
					return false;
				i++;
				j++;
			}
			break;
		}
	}
	if (j<s.length() || j>s.length())
		return false;
	else if (i < p.length())
		return false;

	return true;
	

}

int main()
{
	string s, p;
	cout << "Enter the string to be matched: ";
	cin >> s;
	cout << "Enter the format: ";
	cin >> p;
	cout<<"The output of isMatch function is: "<<isMatch(s, p);
	getchar();
	return 0;
}