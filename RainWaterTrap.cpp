/*
https://leetcode.com/problems/trapping-rain-water/
*/
#include<iostream>
#include<vector>
using namespace std;
static const int arr[] = { 4,2,3 };//{ 0,2,0 };////{ 0,1,0,2,1,0,1,3,2,1,2,1};
int lenA = sizeof(arr) / sizeof(arr[0]);
vector<int> height(arr, arr + sizeof(arr) / sizeof(arr[0]));

int rainWaterTrapAreas(vector<int>& a)
{
	int total = 0,subtotal=0;
	int limit=0, incFlag = 0,limitIndex = 0;
	int i = 0;
	int bucketLength = 0;
	while (i<lenA-1)
	{
		
		if (a[i] != 0)
		{
			if (a[i + 1] >= a[i])
			{
				//Increase loop
				i++;
			}
			else if (a[i + 1] < a[i])
			{
				//Decrease loop
				if (limit==0)
				limit = a[i];
				limitIndex = i;
				i++;
				while (a[i] < limit &&  i<lenA)
				{
					subtotal = subtotal + (limit - a[i]);
					i++;
					bucketLength++;
				}
				if (i < lenA)
				{
					total = total + subtotal;
					bucketLength = 0;
					if (a[i - 1] == limit)
						i--;
				}
					
				else
				{
					if (a[i - 1] >= limit)
						total = total + subtotal;
					else
					{
						/*
						bucketLength = bucketLength - 1; //Subtract for the edges
						subtotal = subtotal - (limit - a[i - 1]) * bucketLength;
						if (subtotal > 0)
							total = total + subtotal;
						*/
						//Alternate approach
						i = limitIndex;
						limit = limit - 1;
						if (limit == 0)
							break;
						subtotal = 0;
						continue;
					}
					break;
				}
				
				limit = 0;
			}
			
			

		}
		else i++;
		

		subtotal = 0;
	}
	return total;
}

int main()
{
	cout << "The amount of rainwater that can be stored is: " << rainWaterTrapAreas(height)<<endl;
	getchar();
	return 0;
}