/*
http://www.geeksforgeeks.org/dynamic-programming-set-5-edit-distance/

Logic after peeking
editdistance (m,n) = min { 1 + editdistance (m-1,n)	:add
						   1 + editdistance (m,n-1)	:delete
						   1 + editdistance (m-1,n-1)	:replace	}



*/
#include<iostream>
#include<string>
using namespace std;

int editDistance(string str1,string str2)
{
	int len1 = str1.length(), len2 = str2.length(),retVal=0;
	int** stringMatrix = new int*[len1 +1];


	//Initialize stringMatrix
	for (int i = 0; i < len1 + 1; i++)
	{
		stringMatrix[i] = new int[len2 + 1];
		for (int j = 0; j < len2 + 1; j++)
			stringMatrix[i][j] = INT_MAX;
	}
	stringMatrix[0][0] = 0;

	int contFlag = 0;
	for (int i = 0; i < len1 + 1; i++)
	{
		for (int j = 0; j < len2 + 1; j++)
		{
			if (i == 0)
				stringMatrix[i][j] = j;
			else if (j==0)
				stringMatrix[i][j] = i;
			else if (str1[i - 1] == str2[j - 1])
			{
				if (stringMatrix[i - 1][j - 1] == INT_MAX)
					stringMatrix[i][j] = 0;
				else
					stringMatrix[i][j] = stringMatrix[i-1][j-1];
				//contFlag = 1;
				//break;
			}
			else
			{
				int min = INT_MAX;
				if(min>stringMatrix[i-1][j-1])
				min = stringMatrix[i-1][j-1];
				if (min>stringMatrix[i - 1][j])
					min = stringMatrix[i-1][j];
				if (min>stringMatrix[i][j-1])
					min = stringMatrix[i][j-1];

				stringMatrix[i][j] = 1 + min;
				
			}
			cout << " " << stringMatrix[i][j];
			
			
		}
		/*
		if (contFlag) {
			contFlag = 0;
			continue;
		}
		*/
			
		cout << endl;
	}


	//Display the matrix
	cout << endl << "The matrix is: " << endl;
	for (int i = 1; i < len1 + 1; i++)
	{
		for (int j = 1; j < len2 + 1; j++)
		{
			cout <<stringMatrix[i][j]<<" ";
		}
		cout << endl;
	}
	
	retVal = stringMatrix[len1][len2];
		
	for (int i = 0; i < len1 + 1; i++)
	{
		delete[] stringMatrix[i];
	}
	delete[] stringMatrix;

	return retVal;
}

int main()
{
	string str1, str2;
	cout << "Enter the two strings: ";
	//getchar();
	getline(cin, str1);
	getline(cin, str2);

	cout << endl << "The edit distance is: " << editDistance(str1, str2);
	getchar();
	return 0;
}
