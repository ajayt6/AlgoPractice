#include<iostream>
#include<string>
#include<vector>
using namespace std;

int solution(vector<int> &A) 
{
	// write your code in C++14 (g++ 6.2.0)
	int flag = 0, wrongOrderIndex = 0, lastPos = 0;
	auto i = A.begin() + 1;
	for (; i != A.end(); i++)
	{
		if (flag == 0)
		{

			if (*(i - 1)>*(i))
			{
				wrongOrderIndex = (i - 1) - A.begin();
				flag = 1;
			}
		}
		else
		{
			if (*(i - 1) <  A[wrongOrderIndex])
				lastPos = (i - A.begin()) - 1;
		}

	}
	if (flag == 0)//There is no problem with sorting
		return 0;
	if (*(i - 1) <  A[wrongOrderIndex])
		lastPos = (i - A.begin()) - 1;
	//Handle two more edge cases 
	//cout<<endl<<"Wrong order index is: "<<wrongOrderIndex<<endl;
	//cout<<endl<<"Size is: "<<A.size()<<endl;
	if ((lastPos == wrongOrderIndex + 1) || (wrongOrderIndex == A.size() - 2))
	{
		for (auto i = A.begin(); i != A.end(); i++)
		{
			if (*i > A[wrongOrderIndex + 1])
			{  // cout<<"Here"<<endl;
				return (wrongOrderIndex - (i - A.begin()) + 2);
			}
		}
	}
	//Handle another edge case of A[wrongOrderIndex] being a repeating element
	while ((wrongOrderIndex >= 1) && (A[wrongOrderIndex - 1] == A[wrongOrderIndex]))
		wrongOrderIndex = wrongOrderIndex - 1;
	
	//cout<<lastPos - wrongOrderIndex +1;
	return lastPos - wrongOrderIndex + 1;
}

int Arr[] = { 1, 2, 6, 5, 5, 8,3, 9, 2 };
vector<int> ArrVect(Arr, Arr + (sizeof(Arr) / sizeof(int)));

int main()
{
	int A = 1, B = 8, C = 3, D = 2;
	//string baseTime = "";
	//baseTime = baseTime + to_string(A) + to_string(B) + to_string(C) + to_string(D);
	//cout << baseTime;
	cout<<endl<<solution(ArrVect);

	getchar();
	return 0;
}