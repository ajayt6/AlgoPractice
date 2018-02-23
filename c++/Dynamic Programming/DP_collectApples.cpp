#include<iostream>
using namespace std;


int apples[][3] = { {1,2,3},{4,6,5},{8,2,1} };

int maxApples()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i == 0 && j == 0)
				;
			else if (i == 0 && j != 0)
				apples[i][j] = apples[i][j] + apples[i][j-1];
			else if (i != 0 && j == 0)
				apples[i][j] = apples[i][j] + apples[i-1][j];
			else
			{
				apples[i][j] = apples[i][j] + (apples[i - 1][j] > apples[i][j - 1] ? apples[i - 1][j]  : apples[i][j - 1]);
			}
		}
	}
	return apples[2][2];
}

int main()
{
	cout << "The max number of apples collected is: " << maxApples();
	getchar();
	return 0;
}