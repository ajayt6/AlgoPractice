/*
https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/

The below is not the correct solution. Below runs correctly for only some cases
*/
#include<iostream>
#include<string>
#include<set>
using namespace std;


int longestSubstring(string s, int k) {
	pair<int, pair<int,int>> arr[26];
	set<int> helperSet;
	int currLength = 0,maxLength = 0,eventFlag =0;

	//First pass 
	for (int i = 0; i < s.length(); i++)
	{
		arr[s[i] - 'a'].first++;
		arr[s[i] - 'a'].second.second = k;
		arr[s[i] - 'a'].second.first++;
	}

	//Second pass
	for (int i = 0; i < s.length(); i++)
	{
		currLength++;
		if (arr[s[i] - 'a'].first < k)
		{
			currLength--;
			if (helperSet.size() == 0 && currLength > maxLength)
				maxLength = currLength;
			currLength = 0;
			if(helperSet.size() > 0)
			{
				helperSet.clear();
			}
			eventFlag = 1;
			continue;
		}

		if(helperSet.find(s[i] - 'a') == helperSet.end())
			helperSet.insert(s[i] - 'a');
		
		if (eventFlag == 1)
		{
			eventFlag = 0;
			arr[s[i] - 'a'].second.second = k;
		}

		arr[s[i] - 'a'].second.second--;
		arr[s[i] - 'a'].second.first--;


		if (arr[s[i] - 'a'].second.second <= 0)
		{
			helperSet.erase(s[i] - 'a');
			//arr[s[i] - 'a'].second.second = k;
		}
		
	}
	if (helperSet.size() == 0 && currLength > maxLength)
		maxLength = currLength;
	

	return maxLength;
}

int main() {
	string input;
	int k;
	cout << "Enter the string: ";
	cin >> input;
	cout << "Enter k: ";
	cin >> k;
	cout << "Longest length is: " << longestSubstring(input,k);
	getchar();
	getchar();
	return 0;
}