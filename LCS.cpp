#include <iostream>
#include <cstring>
using namespace std;


/*	Find the longest increasing subsequence from the given array
L(i) = 1+ Max(L(j))
*/
char a[] = "Welcome to the world";
char b[] = "lwterdl"; //"the world";
int** LCSMatrix = NULL;
int aLen, bLen;

int LCS()
{
	int n = 0;
	
	aLen = strlen(a);
	bLen = strlen(b);

	LCSMatrix = new int*[aLen+1];
	for (int i = 0; i <= aLen; i++)
		LCSMatrix[i] = new int[bLen+1];

	for (int i = 0; i <= aLen; i++)
	{
		for (int j = 0; j <= bLen; j++)
		{
			if (i == 0 || j == 0)
				LCSMatrix[i][j] = 0;
			else if ((i) > 0 && (j) > 0)
			{
				if (a[i - 1] == b[j - 1])
					LCSMatrix[i][j] = LCSMatrix[i - 1][j - 1] + 1;
				else
				{
					LCSMatrix[i][j] = LCSMatrix[i - 1][j] > LCSMatrix[i][j - 1] ? LCSMatrix[i - 1][j] : LCSMatrix[i][j - 1];
				}

			}

			cout << LCSMatrix[i][j]<<" ";
		}
		cout << endl;
	}
	return LCSMatrix[aLen][bLen];
}

int main()
{
	cout<<"The longest commin subsequence is: "<<LCS();
	getchar();
	for (int i = 0; i <= aLen; i++)
		delete[] LCSMatrix[i];
	delete[] LCSMatrix;
	return 0;
}