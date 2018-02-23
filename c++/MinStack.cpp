/*
https://leetcode.com/problems/min-stack/
*/

#include<iostream>
#include<stack>
using namespace std;

class MinStack
{
	stack<pair<int,int>> minStackContainer;
	int min,prevMin;

public:
	MinStack()
	{
		min = INT_MAX;
	}
	void push(int x)
	{
		if (x < min)
		{
			prevMin = min;
			min = x;
		}
		else if (x == min)
			prevMin = min;
		minStackContainer.push(pair<int,int>(x,prevMin));

	}
	void pop()
	{
		if (minStackContainer.top().first == min)
			min = minStackContainer.top().second;
		minStackContainer.pop();
	}
	int top()
	{
		return minStackContainer.top().first;
	}
	int getMin()
	{
		return min;
	}

};

int main()
{
	MinStack minStack;
	
	minStack.push(-2);
	minStack.push(0);
	minStack.push(-3);
	cout<<endl<<"minStack.getMin(): "<<minStack.getMin();   
	minStack.pop();
	minStack.top();      
	cout << endl << "minStack.getMin(): " << minStack.getMin();

	getchar();
	return 0;
}