#include<iostream>
#include<vector>
#include<set>
#include<unordered_set>
using namespace std;

void foo(vector<int> &b)
{
	cout << endl<<"Vector elements are: " << b[0] << " and " << b[1];
	getchar();
}

vector<int> twoSum(vector<int>& nums, int target) {
	unordered_set<int> invertSet;
	int flag = 0;
	for (int i = 0; i<nums.size(); i++)
	{
		invertSet.insert(target - nums[i]);
	}
	int i;
	for (i = 0; i<nums.size(); i++)
		if ((invertSet.find(nums[i]) != invertSet.end()))
		{
			if (nums[i] == target - nums[i])
			{

				if (find(i + 1 + nums.begin(), nums.end(), nums[i]) != nums.end())
				{
					flag = 1;
					break;
				}
			}
		}

	if (flag == 1)
	{
		int a, b;
		a = i;
		b = find(nums.begin(), nums.end(), target - nums[i]) - nums.begin();
		vector<int> returnResult;
		returnResult.push_back(a);
		returnResult.push_back(b);
		return returnResult;
	}
	vector<int> returnResult;
	returnResult.push_back(-1);
	returnResult.push_back(-1);
	return returnResult;
}

int main()
{
	vector<int> a;
	a.push_back(3);
	a.push_back(2);
	a.push_back(4);
	cout << "bubba";
	set<int> c;
	c.insert(1);
	c.insert(2);
	c.insert(3);
	//cout << endl << "The iterator logic is: " << distance(c.find(2),c.begin());

	getchar();
	foo(a);

	cout << endl << "return of twosum is " << twoSum(a, 6)[0] << " and " << twoSum(a, 6)[1];
	getchar();
	return 0;
}