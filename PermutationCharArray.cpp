#include<iostream>
#include<string>
using namespace std;

void permutation(char word[50], int i)
{

	if (i < strlen(word))
	{
		for (int j = i; j < strlen(word); j++)
		{
			//exchange word[i] and word[j]
			char x = word[i];
			word[i] = word[j];
			word[j] = x;

			permutation(word, i + 1);

			//backtrack to maintain correctness exchange word[i] and word[j]
			x = word[i];
			word[i] = word[j];
			word[j] = x;
		}

	}
	else
		cout << endl << word;
}


int main()
{
	char word[50];
	cout << "Enter word: " << endl;
	cin>> word;
	cout << endl << "The permutations are: ";
	//Start permutation
	permutation(word, 0);
	getchar();
	getchar();
	getchar();

}