#include <iostream>
#include <string>
#include<vector>
#include<cmath>
using namespace std;

vector<int> vectorHelper;

int customSignInequality(int a, int b)
{
	/*
	if ((a > b && (-a) > (-b)) || (!(a > b) && !((-a) > (-b))))
		return 1;
	else
		return 0;
	*/

	if (abs(a) / a == abs(b) / b)
		return 0;
	else return 1;

}

int main()
{
	//vectorHelper[0] = 1;
	//vectorHelper[1] = 3;
	vectorHelper.push_back(1);
	vectorHelper.push_back(4);
	vectorHelper[0] = 5;
	cout << "The size of vector is: " << vectorHelper.size()<<" and value of first element is "<<vectorHelper[0];

	cout << "customSignInequality value is: " << customSignInequality(2, 1);
	getchar();
	return 0;
}