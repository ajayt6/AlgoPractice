/*
https://leetcode.com/problems/russian-doll-envelopes/
Not correct answer yet
*/

#include<iostream>
#include<vector>
using namespace std;



pair<int, int> arr[] = { {5,4},{6,4},{6,7},{2,3} };
int len = sizeof(arr) / sizeof(pair<int, int>);
vector < pair<int, int>> envelopes(arr,arr+len);

int maxEnvelopes(vector<pair<int, int>>& envelopes) {

	pair<int,int> **vectArr = NULL;
	int length = INT_MIN, width = INT_MIN,overallMax = 0;
	//Find the max length and width of the matrix to be formed
	for (auto i = envelopes.begin(); i != envelopes.end(); i++)
	{
		if (length < i->first)
			length = i->first;
		if (width < i->second)
			width = i->second;

	}

	vectArr = new pair<int,int>*[length+1];
	for (int i = 0; i < length+1; i++)
		vectArr[i] = new pair<int,int>[width+1];

	//Construct the matrix
	for (auto i = envelopes.begin(); i != envelopes.end(); i++)
	{
		vectArr[i->first][i->second].first = 1;
		vectArr[i->first][i->second].second = 1;
	}
	//Displaying the matrix once
	for (int i = 0; i < length+1; i++)
	{
		for (int j = 0; j < width+1; j++)
		{
			cout << vectArr[i][j].first<<" ";
		}
		cout << endl;
	}

	//Now we have the matrix do a DP collection of apples sort of technique. But in this case movement is possible to to a 1 from 0 only diagonally. All other movements, either right or down

	for (int i = 0; i < length+1; i++)
	{
		for (int j = 0; j < width +1; j++)
		{

			if (vectArr[i][j].first == 1)
			{
				if (i + 1 < length+1 && j + 1 < width+1)
				{
					//Push forward
					vectArr[i + 1][j + 1].second++;
					vectArr[i][j].second--;
				}
			}

			if (i == 0 && j == 0)
				;
			else if (i > 0 && j == 0)	
			{
				vectArr[i][j].second = vectArr[i][j].second + vectArr[i - 1][j].second;
			}
			else if (i == 0 && j > 0)
			{
				vectArr[i][j].second = vectArr[i][j].second + vectArr[i][j-1].second;
			}
			else
			{
									
				vectArr[i][j].second = vectArr[i][j].second + (vectArr[i][j - 1].second > vectArr[i - 1][j].second ? vectArr[i][j - 1].second : vectArr[i - 1][j].second);
				/*
				if (i == 6 && j == 4)
					;
				if (vectArr[i - 1][j - 1].first == 1 && vectArr[i][j].first == 1)
				{
					int tempMax = vectArr[i - 1][j - 1].second;
					if (tempMax < vectArr[i - 1][j].second - vectArr[i - 1][j].first)
						tempMax = vectArr[i - 1][j].second -  vectArr[i - 1][j].first;
					if (tempMax < vectArr[i][j - 1].second -  vectArr[i][j - 1].first)
						tempMax = vectArr[i][j - 1].second -  vectArr[i][j - 1].first;
				}
				else
				{
					vectArr[i][j].second = vectArr[i][j].second + (vectArr[i][j - 1].second > vectArr[i - 1][j].second ? vectArr[i][j - 1].second : vectArr[i - 1][j].second);
				}
				*/
				if (overallMax < vectArr[i][j].second)
					overallMax = vectArr[i][j].second;

			}
		}
	}

	return overallMax;

}

int main()
{
	
	cout<<endl<<maxEnvelopes(envelopes);

	getchar();
	return 0;
}