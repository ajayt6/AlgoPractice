/*
https://leetcode.com/problems/move-zeroes/
*/

#include<iostream>
#include<vector>
using namespace std;

//int Arr[] = { 1,2,3,4 };
//int Arr[] = { 0, 0,0};
int Arr[] = { 0, 1, 0, 3, 12 };
vector<int> arrVector(Arr,Arr+sizeof(Arr)/sizeof(int));

void moveZeroes(vector<int>& nums) {
	//int numZeroes = 0;
	auto i = nums.begin();

	for (; i < nums.end(); i++)
	{
		//cout << *i << " ";
		auto j = i;
		while (*j == 0 && j < nums.end())
		{
			j++;
			//numZeroes++;
		}
		if (j == nums.end())
		{
			//cout << "Debug print: Remaining are 0s" << endl;
			break;	//As remaining are all 0s
			
		}
		if (i == j)
			continue;
		//swap
		int temp;
		temp = *i;
		*i = *j;
		*j = temp;
	}
	//Fill remaining positions with 0s
	for (; i < nums.end(); i++)
		*i = 0;

}

int main()
{
	moveZeroes(arrVector);
	for (auto i = arrVector.begin(); i != arrVector.end(); i++)
		cout << *i << " ";
	getchar();
	return 0;
}