#include<iostream>
#include<sstream>
using namespace std;


int lengthOfLongestSubstring(string s) {

	int i = 0, start, end, max, current, nstart, nend;

	int charArray[128][2];
	max = 0;
	current = 0;
	start = 0;

	if (s.length() == 0)
		return 0;

	for (i = 0; i < 128; i++)
	{
		charArray[i][0] = 0;
		charArray[i][1] = 0;
	}

	for (i = 0; i<s.length(); i++)
	{
		if (charArray[s[i]][0] == 1)
		{
			//current = i - charArray[s[i]][1];
			start = (charArray[s[i]][1] + 1 > start) ? charArray[s[i]][1] + 1 : start;
			//clean alphabetSmall
			/*for (int j = 0; j < 128; j++)
			{
				charArray[j][0] = 0;
			}*/
			//set charArray for current character
			charArray[s[i]][0] = 1;
			charArray[s[i]][1] = i;
		}
		else
		{
			charArray[s[i]][0] = 1;
			charArray[s[i]][1] = i;
			
		}
		if (i - start + 1 > max)
			max = i - start + 1;



	}
	return max;

}

int main()
{
	string input;
	cout << "Enter string";
	getline(cin, input);
	cout << endl << lengthOfLongestSubstring(input);
	getchar();
	return 0;

}