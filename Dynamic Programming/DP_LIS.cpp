#include <iostream>
#include <string>
using namespace std;


/*	Find the longest increasing subsequence from the given array
	L(i) = 1+ Max(L(j))
*/
int LISArr[] = {23,13,45,67,32,43,65,87,23,9};
int* LISSolution = NULL;
int len = 0;
int LISlen()
{
	int len = sizeof(LISArr) / sizeof(int);
	LISSolution = new int[len];

	for (int i = 0; i < len; i++)
		LISSolution[i] = 1;

	for(int i=1;i<len;i++)
	for (int j = 0; j < i; j++)
	{
		if (LISArr[j] < LISArr[i] && (LISSolution[j] + 1 > LISSolution[i]))
			LISSolution[i] = LISSolution[j] + 1;
	}
	int max = 0;

	cout << "The values of solution array are: " << endl;
	for (int i = 0; i < len; i++)
	{
		cout << LISSolution[i] << " ";
		if (max < LISSolution[i])
			max = LISSolution[i];
	}

	//delete the solution array
	delete[] LISSolution;

	return max;
}

int main()
{
	cout <<endl<<"The length of LIS is: " << LISlen();
	getchar();
	getchar();

	return 0;
}