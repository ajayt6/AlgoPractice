#include <iostream>
#include <string>
#include<cmath>
using namespace std;


int zigZagArray[] = { 1,7,4,5,5 };
int len;
int *ZZS = NULL;

//return 0 if equal, 1 otherwise
int customSignInequality(int a, int b)
{
	if (abs(a) / a == abs(b) / b)
		return 0;
	else return 1;

}

int LZZS()
{
	len = sizeof(zigZagArray) / sizeof(int);
	ZZS = new int[len];
	for (int i = 0; i < len; i++)
		ZZS[i] = 1;
	//if (ZZS[2] < ZZS[1])
		//ZZS[2] = -2;
	int k;
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < i; j++)
		{
			k = zigZagArray[i] - zigZagArray[j];
			if (j == 0)
			{

				if ((abs(ZZS[j]) + 1 > abs(ZZS[i])))
				{
					if (k == 0)
						ZZS[i] = 1 * (abs(ZZS[j]) + 1);	//taking care of 0
					else
						ZZS[i] = abs(k) / (k) * (abs(ZZS[j]) + 1);
				}
					
			}
			else
			{
				if (k == 0)
				{
					if (customSignInequality(1, ZZS[j]) && (abs(ZZS[j]) + 1 > abs(ZZS[i])))
						ZZS[i] = 1 * (abs(ZZS[j]) + 1);
				}
				else
				{
					if (customSignInequality(zigZagArray[i] - zigZagArray[j], ZZS[j]) && (abs(ZZS[j]) + 1 > abs(ZZS[i])))
						ZZS[i] = abs(zigZagArray[i] - zigZagArray[j]) / (zigZagArray[i] - zigZagArray[j]) * (abs(ZZS[j]) + 1);
				}
			}
		}

	}

	return abs(ZZS[len-1]);

}


int main()
{
	cout<<"The length of longest zigzag subsequence is: " <<LZZS();
	cout << "The entire array of longest zigzag subsequence is: " << endl;
	for (int i = 0; i < len; i++)
		cout << ZZS[i] << endl;
	getchar();
	return 0;

}