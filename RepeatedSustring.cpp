/*
https://leetcode.com/problems/repeated-substring-pattern/

This is not correct solution for the above problem. FOr the correct solution, substrings of lenght staisfying the property of being a divisor of the original string are appended to each other quotient number of times and compared to the original string -> this is the easy solution
*/

#include<iostream>
#include<string>
using namespace std;

bool repeatedSubstringPattern(string str) {
	int a[26], len = sizeof(a)/sizeof(int),max = 0, flag=0;

	for (int i = 0; i < len; i++)
		a[i] = 0;

	for (int i = 0; i < str.length(); i++)
		a[str[i] - 'a'] ++;

	for (int i = 0; i < len; i++)
	{
		if (a[i] != 0)
		{
			if (flag == 0)
			{
				max = a[i];
				flag = 1;
				if (max == 1)
					return false;
			}
			else
			{
				if (max != a[i])
					return false;
			}

		}
	}

	return true;
}

int main()
{
	string str;

	cout<<"Enter string of choice"<<endl;
	cin >> str;
	getchar();
	cout << "The result is: " << repeatedSubstringPattern(str);
	getchar();
	return 0;
}