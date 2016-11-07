#include <iostream>
#include <string>
using namespace std;

int main()
{
	string a, b;
	int rem = 0;
	int carry = 0;
	int selectionFlag = 0;
	cout << "Enter two numbers" << endl;
	getline(cin, a);
	getline(cin, b);
	int k = 0, i = 0, j = 0;
	a.length() > b.length() ? selectionFlag = 1 : selectionFlag = 0;
	int len = selectionFlag ? a.length() : b.length();
	len++; //Since result can have one more digit

	char *c = new char(len + 1);
	for (i = 0; i < len; i++)
		c[i] = '0';
	c[i] = '\0';

	k = len-1;

		
		for (j = a.length() - 1 , i = b.length() - 1; i >= 0 && j >= 0; j--,i--,k--)
		{
			int num1 = b[i] - 48;
			int num2 = a[j] - 48;
			int quotient = num2+num1;
			rem = quotient % 10;

			//int digit = (rem + (c[k] - 48) + carry);
			c[k] = rem + c[k];

			c[k-1] = quotient / 10 + '0';
		}

		//k = selectionFlag ? j : i ;
		k++;
		i++;
		j++;
		if (selectionFlag == 1)
		{
			int quotient = c[1 + j + i] - '0' + a[j];
			rem = quotient % 10;
			c[k] = rem + '0';
			c[k-1] = quotient / 10 + '0';
			j--;
			for(j;j>=0;j--)
			c[k] = c[k] + a[j] ;

		}
		else
		{
			int quotient = c[1 + j + i] - '0' + b[i];
			rem = quotient % 10;
			c[k] = rem + '0';
			c[k - 1] = quotient / 10 + '0';
			i--;
			for (i; i >= 0; i--)
				c[k] = c[k] + b[i] ;

		}
		 
		c[0] = carry + '0';

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