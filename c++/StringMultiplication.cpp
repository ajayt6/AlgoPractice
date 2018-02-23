#include <iostream>
#include <string>
using namespace std;

int main()
{
	string a, b;
	int rem = 0;
	int carry = 0;
	cout << "Enter two numbers" << endl;
	getline(cin, a);
	getline(cin, b);
	int k = 0, i = 0, j = 0;
	int len = a.length() + b.length();
	char *c = new char(len+1);
	for ( i = 0; i < len; i++)
		c[i] = '0';
	c[i] = '\0';
	
	for (i = b.length()-1; i >=0; i--)
	{
		carry = 0;
		int num1 = b[i] - 48;
		for (j = a.length()-1; j >=0 ; j--)
		{
			int num2 = a[j] - 48;
			int quotient = num2*num1;
			rem = quotient % 10;
			
			int digit = (rem + (c[ 1 + j +i] - 48) + carry);
			c[1 + j + i] = digit % 10 + '0';

			carry = quotient / 10 + digit/10;
		}
		c[1 + j + i] = c[1 + j + i] + carry;
		
	}
	c[0] = carry+'0';

	string d = string(c);
	cout << "Answer is: " << d;
	//for (int i = 0; i < len; i++)
		//cout << c[i];
	//deallocate c
	delete[] c;
	getchar();
	getchar();

	return 0;
}