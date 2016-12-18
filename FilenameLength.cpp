/*
https://leetcode.com/problems/longest-absolute-file-path/
*/
#include<iostream>
#include<stack>
#include<string>
using namespace std;

string input = "dir\n    file.txt";
//string input = "a.txt";
//string input = "dir\n\tsubdir1";
//string input = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext\n\t\t\tsubsubsubdir2";//"dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext";// "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext";
//string input = "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext";
int lengthLongestPath(string input) {

	int totLength = 0,subLength = 0,numTabs=0,pos=0,fileFlag=0,longest = 0,tabFlag=1,nonCount = 0;
	stack<pair<int,int>> folderStack;
	int i = 0;
	for (i = 0; i < input.length(); i++)
	{
		
		//totLength = 0;
		if (tabFlag == 1)
		{
			pos = i;
			tabFlag = 0;
		}
		if (input[i] == ' ')
			nonCount++;

		else if (input[i] == '.')
			fileFlag = 1;
		
		if (input[i] == '\n'  )
		{
			subLength = i - pos -nonCount;
			nonCount = 0;
			pos = 0;
			/*if (folderStack.size() > 0)
				totLength = totLength + subLength - folderStack.top().second;
			else*/
				
			if (fileFlag == 1)
			{
				totLength = totLength + subLength;
				fileFlag = 0;
				if (longest < totLength)
					longest = totLength;
				numTabs = 0;
				totLength = totLength - subLength;
			}
			else
			{
				totLength = totLength + subLength + 1;
				folderStack.push(pair<int,int>(subLength,numTabs));
				numTabs = 0;
			}
			
			subLength = 0;
			i++;
			while (input[i] == '\t')
			{
				tabFlag = 1;
				i++;
				numTabs++;
			}
			i--;
			while (folderStack.size()>0 && folderStack.top().second >= numTabs)
			{
				totLength = totLength - folderStack.top().first -1;
				folderStack.pop();
			}

		}

	}
	if (fileFlag == 1)
	{
		subLength = i - pos - nonCount;
		nonCount = 0;
		/*
		if (folderStack.size() > 0)
			totLength = totLength + subLength - folderStack.top().second;
		else*/
			totLength = totLength + subLength;
		
		fileFlag = 0;
		while (folderStack.size()>0 && folderStack.top().second >= numTabs)
		{
			totLength = totLength - folderStack.top().first -1;
			folderStack.pop();
		}
		if (longest < totLength)
			longest = totLength;
	}


	
	return longest;
}

int main()
{
	cout << "The longest file length is: " << lengthLongestPath(input);
	getchar();
	return 0;
}