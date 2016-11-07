#include <iostream>
#include <string>
using namespace std;


/*	Find the longest increasing subsequence from the given array
	L(i) = 1+ Max(L(j))
*/
int LISArr[10] = {23,13,45,67,32,43,65,87,23,9};

int LISlen()
{
	for (int j = 0; j < 10; j++)
	{
		if(LISArr[j]< LISArr[j+1])
			LISval = 1 + max()
	}


	return 0;
}

int main()
{



	cout << "The length of LIS is: " << LISlen();
	getchar();
	getchar();

	return 0;
}