#include<iostream>
#include<string>
using namespace std;

int maxTime = INT_MIN;
string maxTimeStr = "";

void permutation(string base, int n)
{
	if (n<base.length())
	{
		for (int i = n; i<base.length(); i++)
		{
			//Swap and then recurse
			char temp = base[i];
			base[i] = base[n];
			base[n] = temp;

			permutation(base, n + 1);

		}

	}
	else
	{
		int hour = (base[0] - '0') * 10 + base[1] - '0';
		int minute = (base[2] - '0') * 10 + base[3] - '0';
		if ((hour >= 0 && hour <= 23) && (minute >= 0 && minute <= 59))
		{
			//Valid
			int timeNumeric = hour * 100 + minute;
			if (timeNumeric > maxTime)
			{
				maxTime = timeNumeric;
				maxTimeStr = base.substr(0, 2) + ":" + base.substr(2, 2);
				//maxTimeStr = to_string(base[0]) + to_string(base[1]) + ":" + to_string(base[2]) + to_string(base[3]); 
			}
		}
	}
}

string solution(int A, int B, int C, int D) {
	// write your code in C++14 (g++ 6.2.0)
	string baseTime = "";
	baseTime = baseTime + to_string(A) + to_string(B) + to_string(C) + to_string(D);
	//cout<<baseTime;

	permutation(baseTime, 0);
	//cout<<to_string(maxTime)<<endl;
	//cout<<maxTimeStr;
	if (maxTime<0)
		return "NOT POSSIBLE";
	return maxTimeStr;

}

int main()
{
	int A = 1, B = 8, C = 3, D = 2;
	//string baseTime = "";
	//baseTime = baseTime + to_string(A) + to_string(B) + to_string(C) + to_string(D);
	//cout << baseTime;
	solution(A, B, C, D);

	getchar();
	return 0;
}