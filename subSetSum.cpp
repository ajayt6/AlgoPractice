/*
http://www.geeksforgeeks.org/dynamic-programming-subset-sum-problem/

sum with number 
and
sum without number

array arr of size m

fun(m,sum) = {	fun (m-1,sum)
				fun (m-1,sum-arr[m])	}

*/
#include<iostream>
#include<string>
using namespace std;


int arr[] = { 3,2,6,1,9 };

bool subSetSum(int sum)
{
	int len = sizeof(arr) / sizeof(int);
	
	if (arr[0] == sum)
		return false;

	int* subSetVal = new int[len];

	
	for (int i = 1; i < len; i++)
	{


	}

	return false;
}

int main()
{
	int sum;
	cout << "Enter the sum: ";
	cin >> sum;

	cout << endl << "The subSetSum exists value is: " << subSetSum(sum);
	getchar();
	return 0;
}