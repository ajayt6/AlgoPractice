/*
https://leetcode.com/problems/binary-watch/
The solution below is worng and wil run infinitely(?). Consult solution in link. Great solution and approach
*/
#include<vector>
#include<iostream>
#include<bitset>
#include<string>
using namespace std;


vector<string> timeSet;
void timeCreate(bitset<10> time)
{
	bitset<4>hour;
	bitset<6> minute;
	int hourInt=0, minuteInt = 0;
	string timeString = "";

	for (int i = 0; i < 4; i++)
		hour[i] = time[i];
	for (int i = 0; i < 6; i++)
		minute[i] = time[i + 4];

	hourInt = hour.to_ulong();
	minuteInt = minute.to_ulong();
	timeString.append(to_string(hourInt));
	timeString.append(":");
	timeString.append(to_string(minuteInt));
	timeSet.push_back(timeString);


}

void permutation(bitset<10> word, int i,int len)
{

	if (i < len)
	{
		for (int j = i; j < len; j++)
		{
			//exchange word[i] and word[j]
			char x = word[i];
			word[i] = word[j];
			word[j] = x;

			permutation(word, i + 1,len);

			//backtrack to maintain correctness exchange word[i] and word[j]
			x = word[i];
			word[i] = word[j];
			word[j] = x;
		}

	}
	else
	{
		//cout << endl << word;
		//Function to convert to time string and store in string vector
		timeCreate(word);
	}
		
}

vector<string> readBinaryWatch(int num) {
	bitset<10> time;
	//int minute[6];
	for (int i = 0; i < num; i++)
	{
		time[i] = 1;
	}
	permutation(time, 0, 10);
	//permutation(hour, 0, 4);
	return timeSet;
}

int main()
{
	int n;
	cout << "Enter n: ";
	cin >> n;
	vector<string> times = readBinaryWatch(n);
	for (auto i : times)
		cout << endl << i;
	getchar();
	getchar();
	return 0;
}