#include<iostream>
#include<cmath>
using namespace std;

//Below accepted solution used a long long for cehcking overflow
/*
https://discuss.leetcode.com/topic/6005/shortest-code-possible-in-c/2
class Solution {
public:
int reverse(int x) {
long long res = 0;
while(x) {
res = res*10 + x%10;
x /= 10;
}
return (res<INT_MIN || res>INT_MAX) ? 0 : res;
}
};
*/
int reverse_helper(long x, long y)
{
	long dig;
	//
	{
		dig = y + x % 10;
		x = x / 10;

		if (x != 0)
		{
			//if (dig * 10 >  long(2 << 32))
			//	return 0;
			dig = reverse_helper(x, dig * 10);
		}


	}
	return dig;
}

int reverse(int x) {
	return reverse_helper(long(x), 0);

}

int main()
{
	int n;
	
	cout << "Enter integer: ";
	cin >> n;
	//int sighDigit = abs(n) / n;
	cout << "sizeof(int): " << sizeof(int)<<endl;
	cout << "sizeof(unsigned long): " << sizeof(unsigned long) << endl;
	cout << "1 << 32: " << (1 << 32) << endl;
	cout << "1 << 31: " << (1 << 31) << endl;
	cout << "1 << 30: " << (1 << 30) << endl;
	cout << "2 << 5: " << (2 << 5) << endl;
	cout << "2 >> 5: " << (2 >> 5) << endl;
	cout << "-45 % 10 : " << (-45 % 10) << endl;
	cout << "The reversed integer is: " <<  reverse(n);
	getchar();
	getchar();
	return 0;
}