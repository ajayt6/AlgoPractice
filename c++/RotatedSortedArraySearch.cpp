/*

https://leetcode.com/problems/search-in-rotated-sorted-array/
***IMP READ THIS
My answer is not being accepted in leetcode and is failing at the test case:
Input:
[3,5,1]
1
Output:
0
Expected:
2

I think the test case is wrong, as according to question index should indeed be 0 as in proper increasing sorted order 1 would occur first

/
#include <iostream>
#include <vector>

using namespace std;

int search(vector<int>& nums, int target) {

	int index = -1,rotateFlag = 0,rotatePosIncreasing = -1, rotatePosDecreasing = -1;



	for (auto i = nums.begin(); i != nums.end(); i++)
	{
		if (*i == target)
		{
			index = i - nums.begin();
		}
		if (rotatePosIncreasing== -1 && i < nums.end()-1  && *i > *(i + 1))
		{
			rotatePosIncreasing = (i - nums.begin()) + 1;
		}
		if (rotatePosDecreasing == -1 &&  i < nums.end() - 1 && *i < *(i + 1))
		{
			rotatePosDecreasing = (i - nums.begin()) + 1;
		}
		/*
		if (*i == target && rotatePosIncreasing != -1)
		{
			break;
		}
		*/
	}

	cout << endl << "index: " << index << endl << "rotatePosIncreasing: " << rotatePosIncreasing <<endl << "rotatePosDecreasing: " << rotatePosDecreasing << endl;

	if (index != -1   && rotatePosIncreasing != -1 && rotatePosDecreasing != -1)
	{
		if (rotatePosDecreasing < rotatePosIncreasing)
		{
			if (index < rotatePosIncreasing)
				index = index + rotatePosIncreasing;
			else
				index = index - rotatePosIncreasing;
		}
		else
		{
			if (index < rotatePosDecreasing)
				index = index + rotatePosDecreasing;
			else
				index = index - rotatePosDecreasing;
		}
	}
	return index;
}

int main()
{
	//For reference
	//vector<int> nums = { 0 ,1 ,2 ,4 ,5 ,6 ,7 };
	//vector<int> nums = { 4, 5, 6, 7, 0, 1, 2 };
	//vector<int> nums = {  7,6,5,4,1, 0, 10, 9 };
	vector<int> nums = { 3,1};
	cout << "Position of element is: " << search(nums, 1);
	getchar();
	return 0;
}