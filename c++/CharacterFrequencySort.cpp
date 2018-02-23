/*
https://leetcode.com/problems/sort-characters-by-frequency/
*/

#include<iostream>
#include<unordered_map >
#include<string>
#include<algorithm>

using namespace std;

unordered_map<char, int> uMap;
pair<int, char> characterSpecialMap[128];


bool comp(const pair<int, char>& lhs, const pair<int, char>& rhs)
{
	return lhs.first > rhs.first;
}


string charFrequencyPrint(string s)
{
	string modifiedString = "";

	/*
	for (int i = 0; i < s.length(); i++)
	{

		if (uMap.find(s[i]) != uMap.end())
			uMap[s[i]] = uMap[s[i]] + 1;
		else
			uMap.insert(make_pair(s[i], 1));
	}

	cout << "The contents of the map are: "<<endl;
	for (auto i = uMap.begin(); i != uMap.end(); i++)
		cout << i->first << " : " << i->second << endl;

	*/


	//Initialize characterSpecialMap with (0,0)
	for (int i = 0; i < 128; i++)
		characterSpecialMap[i] = pair<int,char>(0,0);

	//Iterate through input string
	for (int i = 0; i < s.length(); i++)
	{		
		characterSpecialMap[s[i]] = pair<int,char>(characterSpecialMap[s[i]].first+1, s[i]);	
	}

	//Sort the characterSpecialMap array
	/* std::sort(characterSpecialMap, characterSpecialMap + 127,
		[](pair<int, char> const & a, pair<int, char> const & b) -> bool
	{ return a.first < b.first; });
	*/
	std::sort(characterSpecialMap, characterSpecialMap + 127, comp);


	//Display characterSpecialMap
	/*
	cout << endl<<"The characterSpecialMap is: "<<endl;
	for (int i = 0; i<128; i++)
		cout << characterSpecialMap[i].first << " : " << characterSpecialMap[i].second << endl;
	*/

	//Assign to modifiedString
	for (int i = 0; characterSpecialMap[i].first != 0; i++)
		for(int j = 0; j < characterSpecialMap[i].first; j++)
			modifiedString += (characterSpecialMap[i].second);

	return modifiedString;
}

int main()
{
	string inputString;
	cout << "Enter string: ";
	cin >> inputString;

	cout << endl << "The output is: " << charFrequencyPrint(inputString);
	getchar();
	getchar();
	return 0;


}