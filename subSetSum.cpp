/*
http://www.geeksforgeeks.org/dynamic-programming-subset-sum-problem/

sum with number 
and
sum without number

array arr of size m

fun(m,sum) = {	fun (m-1,sum)
				fun (m-1,sum-arr[m])	}

On thinking, subset sum problem with positive integers is a very easy version of coin sum problem
BUT it's not
*/
#include<iostream>
#include<string>
using namespace std;


int arr[] = { 3,2,6,9 };

bool subSetSum(int sum)
{
	int len = sizeof(arr) / sizeof(int);
	
	if (arr[0] == sum)
		return true;

	bool* subSetVal = new bool[len];
	int* subSetSumsArray = new int[sum+1];

	for (int i = 0; i <= sum; i++)
		subSetSumsArray[i] = 0;
	
	subSetSumsArray[0] = 1;

	for (int i = 0; i <= sum; i++)
	{
		for (int j = 0; j < len; j++)
		{
			if (arr[j] <= i   && subSetSumsArray[i - arr[j]] == 1)
				subSetSumsArray[i] = 1;
		}
		cout << subSetSumsArray[i] << " ";
	}

	cout << endl<<"The array is: " << endl;

	for (int i = 0; i <= sum; i++)
		cout<<subSetSumsArray[i] << " ";

	if (subSetSumsArray[sum] != 0)
		return true;
	else
	return false;
}

int main()
{
	int sum;
	cout << "Enter the sum: ";
	cin >> sum;

	cout << endl << "The subSetSum exists value is: " << subSetSum(sum);
	getchar();
	getchar();
	return 0;
}