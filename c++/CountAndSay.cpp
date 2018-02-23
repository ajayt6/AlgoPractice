/*
https://leetcode.com/problems/count-and-say/
*/

#include<iostream>
#include<string>
using namespace std;

string countAndSay(int n) {
	string sub = "", sequence = "", newSub = "";
	if (n < 0) return "";
	sub.append(to_string(1));
	sequence.append(to_string(1)).append(", ");
	for (int i = 1; i < n; i++)
	{
		int j = 0;
		while (j < sub.length())
		{
			int current = sub[j] - '0';
			
			int count = 0;
			while ((current == sub[j] - '0') && (j < sub.length()))
			{
				j++;
				count++;
			}
			newSub.append(to_string(count)).append(to_string(current));
			

		}
		
		sequence.append(newSub).append(", ");

		sub = newSub;
		newSub = "";
	}
	sequence = sequence.substr(0, sequence.length() - 2);
	return sub;

}

int main()
{
	int n;
	string sequence = "";
	cout << "Enter n: ";
	cin >> n;
	cout << "The sequence is as follows: " << endl;
	sequence = countAndSay(n);
	
	cout << (sequence.c_str());
	getchar();
	getchar();
	return 0;
}