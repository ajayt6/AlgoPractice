#include<iostream>
#include<sstream>
using namespace std;
int main()
{
	int n;
	string word;
	stringstream wordStream;

	cout << "Enter number of words: "<<endl;
	cin >> n;

	cout << "Enter words"<<endl;
	getchar();
	//cin.sync();
	while (n > 0)
	{
		getline(cin,word);
		
		cout << endl << "value of n is: " << n <<" and word is: "<<word<<endl;
		wordStream << word;
		n--;
	}
	cout << endl << "The entered stream is: " << wordStream.str();
	getchar();
	return 0;
}