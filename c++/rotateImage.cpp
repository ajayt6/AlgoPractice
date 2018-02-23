/*
The belwo sol is wrong
*/
#include<iostream>
using namespace std;

int a[][4] = { {1,2,3,4},
			 {5,6,7,8},
			 {9,10,11,12},
			 {13,14,15,16} };

int numRows = sizeof(a) / sizeof(a[0]);
int numCols = sizeof(a[0]) / sizeof(int);

void rotateImage()
{
	int temp;
	for (int i=0;i<numRows-1-i;i++)
		for (int j = i; j < numCols - 1 - j; j++)
		{
			temp = a[i][j];

			//1)Rotate element from  last row first column to first row first column  and so on
			a[i][j] = a[numRows-1-i][j];
			//2)
			a[numRows - 1 - i][j] = a[numRows - 1 - i][numCols - 1 - j];
			//3)
			a[numRows - 1 - i][numCols - 1 - j] = a[i][numCols - 1 - j];
			//4)
			a[i][numCols - 1 - j] = temp;

		}

}
int main()
{
	cout << "Before rotation: " << endl;
	for (int i = 0; i < numRows; i++)
	{
		for (int j = 0; j < numCols; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
	
	rotateImage();

	cout << "After rotation: " << endl;
	for (int i = 0; i < numRows; i++)
	{
		for (int j = 0; j < numCols; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
	getchar();
	return 0;
}
