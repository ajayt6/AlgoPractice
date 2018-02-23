#include <iostream>
#include <string>
using namespace std;

int *fibArr = NULL;

int fib(int n)
{
	if (fibArr != NULL && fibArr[n] != 0)
		return fibArr[n];

	return fib(n-1)+fib(n-2);
}

int main()
{
	int n;
	cout << "Enter fibonacci number limit: ";
	cin >> n;

	fibArr = new int[n+1];

	for (int i = 0; i < n+1; i++)
		fibArr[i] = 0;

	fibArr[0] = 1;
	fibArr[1] = 1;

	cout << "The fib value is: " << fib(n);
	getchar();
	getchar();

	return 0;
}