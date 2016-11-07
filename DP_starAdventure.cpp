/*
Problem StarAdventure – SRM 208 Div 1:

Given a matrix with M rows and N columns (N x M). In each cell there’s a number of apples.
1)You start from the upper-left corner of the matrix. You can go down or right one cell. You need to arrive to the bottom-right corner.
2)Then you need to go back to the upper-left cell by going each step one cell left or up. 
3)Having arrived at this upper-left cell, you need to go again back to the bottom-right cell.

Find the maximum number of apples you can collect.
When you pass through a cell – you collect all the apples left there.

Restrictions: 1 < N, M <= 50 ; each cell contains between 0 and 1000 apples inclusive.
*/


/*
My observations
1)We need to maintain the original matrix intact. So make copies
2)Maintain backtracking info. For that another matrix is needed

Time Complexity = O(n^2)
Space Complexity = O(n^2)
*/

#include<iostream>
using namespace std;


int apples[][3] = { { 1,2,3 },{ 4,6,5 },{ 8,2,1 } };
int dupApples[3][3];
pair<int,int> backtrackApples[3][3];

int maxApples()
{
	int totalApples = 0;
	for (int k = 0; k < 3; k++)
	{

		//Do the normal copying
		if (k != 1)
		{
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					dupApples[i][j] = apples[i][j];
				}
			}
		}
		//Do reverse copying
		else
		{
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					dupApples[3-i-1][3-j-1] = apples[i][j];
				}
			}

		}


		//The collection round
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (i == 0 && j == 0)
					backtrackApples[i][j] = make_pair(-1, -1);
				else if (i == 0 && j != 0)
				{
					dupApples[i][j] = dupApples[i][j] + dupApples[i][j - 1];
					backtrackApples[i][j] = make_pair(i, j - 1);
				}

				else if (i != 0 && j == 0)
				{
					dupApples[i][j] = dupApples[i][j] + dupApples[i - 1][j];
					backtrackApples[i][j] = make_pair(i - 1, j);
				}
				else
				{
					dupApples[i][j] = dupApples[i][j] + (dupApples[i - 1][j] > dupApples[i][j - 1] ? dupApples[i - 1][j] : dupApples[i][j - 1]);
					backtrackApples[i][j] = dupApples[i - 1][j] > dupApples[i][j - 1] ? make_pair(i - 1, j) : make_pair(i, j - 1);
				}
			}
		}
		totalApples = totalApples + dupApples[2][2];

		//Do the backtracking and clear apples
		if (k != 1)
		{
				int i=2, j=2,newI,newJ;
				while(i>=0 && j>=0)
				{
					apples[i][j] = 0;
					newI = backtrackApples[i][j].first;
					newJ = backtrackApples[i][j].second;

					i = newI;
					j = newJ;
				}
		}
		//Do reverse backtracking
		else
		{
				int i = 2, j = 2, newI, newJ;
				while (i >= 0 && j >= 0)
				{
					apples[3-i-1][3-j-1] = 0;
					newI = backtrackApples[i][j].first;
					newJ = backtrackApples[i][j].second;

					i = newI;
					j = newJ;
				}
		}

		cout << endl << "The backtrack matrix after round " << k << " is: " << endl;

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << backtrackApples[i][j].first << " "<< backtrackApples[i][j].second<<"		";
			}
			cout << endl;
		}

		cout << endl << "The apple matrix after round " << k << " is: " << endl;

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout<<apples[i][j]<<" ";
			}
			cout << endl;
		}

	}


	return totalApples;
}


int main()
{
	cout << "The max number of apples collected is: " << maxApples();
	getchar();
	return 0;
}