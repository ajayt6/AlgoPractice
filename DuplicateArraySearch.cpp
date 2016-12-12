/* Count of a given number in a sorted array containing duplicates. */
//The trick is to use modified binary search to contain complexity to O(log n) even though after first binary search and number find , it will be tempting to sue linear left and right counters 
#include<iostream>
#include<string>
#include<cmath>
using namespace std;

//int Arr[] = { 2,5,6,7,7,7,7,14,78 };
//int Arr[] = { 7,7,7,7,7,14,78 };
int Arr[] = { 7,7,7,7,7,7 };

int unModBinarySearch(int num)
{
	int left = 0;
	int lenArr = sizeof(Arr) / sizeof(int);
	int right = lenArr - 1;
	int mid = 0;

	while (left <= right)
	{
		mid = int(ceil((float(right) + left ) / 2));

		if (Arr[mid] == num)
			return mid;
		else if (Arr[mid] < num)
		{
			left = mid + 1;
		}
		else if (Arr[mid] > num)
		{
			right = mid - 1;
		}

	}
	return -1;
}

int leftModBinarySearch(int num)
{
	int left = 0;
	int lenArr = sizeof(Arr) / sizeof(int);
	int right = lenArr - 1;
	int mid = 0;

	while (left <= right)
	{
		mid = int(ceil((float(right) + left) / 2));

		if ( Arr[mid] == num && (Arr[mid - 1] < Arr[mid]  || mid == 0) )
			return mid;
		else if (Arr[mid] < num)
		{
			left = mid + 1;
		}
		else if (Arr[mid] >= num)
		{
			right = mid - 1;
		}

	}
	return -1;
}

int rightModBinarySearch(int num)
{
	int left = 0;
	int lenArr = sizeof(Arr) / sizeof(int);
	int right = lenArr - 1;
	int mid = 0;

	while (left <= right)
	{
		mid = int(ceil((float(right) + left) / 2));

		if (Arr[mid] == num && (Arr[mid + 1] > Arr[mid] || mid == lenArr-1))
			return mid;
		else if (Arr[mid] <= num)
		{
			left = mid + 1;
		}
		else if (Arr[mid] > num)
		{
			right = mid - 1;
		}

	}
	return -1;
}

int countDupArr(int num)
{
	int count = 0;
	//return unModBinarySearch(num);
	int leftEnd = leftModBinarySearch(num);
	int rightEnd = rightModBinarySearch(num);

	if (leftEnd != -1 && rightEnd != -1)
		count = rightEnd - leftEnd + 1;

	return count;

}

int main()
{
	int num;
	cout << "Enter the number: ";
	cin >> num;

	cout << endl << "The count is: " << countDupArr(num);
	getchar();
	getchar();
	return 0;
}