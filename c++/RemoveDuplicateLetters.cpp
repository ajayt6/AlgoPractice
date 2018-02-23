/*
https://leetcode.com/problems/remove-duplicate-letters/
*/
#include<iostream>
#include<string>
#include<stack>
using namespace std;

string removeDuplicateLetters(string s) {
	stack<char> dupStack;
	pair<int, int> a[26];//First element to indicate number of ocurrences. Second element as stack helper
	string result = "";

	for (int i = 0; i < s.length(); i++)
	{
		a[s[i] - 'a'].first++;
	}

	for (int i = 0; i < s.length(); i++)
	{
		if (dupStack.size() == 0) 
		{
			dupStack.push(s[i]);
			
			a[dupStack.top() - 'a'].second = 1;
		}
		else
		{
			while (dupStack.size() > 0 && dupStack.top() > s[i] && a[dupStack.top() - 'a'].first > 1  && a[s[i] - 'a'].second != 1)
			{
				if (a[s[i] - 'a'].second != 1)
				{
					a[dupStack.top() - 'a'].first--;
					a[dupStack.top() - 'a'].second = 0;
					dupStack.pop();
				}
				
				
			}
			if (a[s[i] - 'a'].second != 1)
			{
				dupStack.push(s[i]);
				a[s[i] - 'a'].second = 1;
			}
			else
				a[s[i] - 'a'].first--;
			


		}

	}

	//Now transfer from stack to 
	while (dupStack.size() > 0)
	{
		result.insert(0,1,dupStack.top());
		dupStack.pop();
	}

	return result;

}


int main()
{
	string str;
	cout << "Enter the string: " << endl;
	cin >> str;
	getchar();
	cout << "The output string is: " << removeDuplicateLetters(str);

	getchar();
	return 0;
}