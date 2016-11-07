#include<iostream>
#include<string>
using namespace std;

void permutation(string word, int i)
{

	if (i < word.length())
	{
		for (int j = i; j < word.length(); j++)
		{
			//exchange word[i] and word[j]
			char x = word[i];
			word[i] = word[j];
			word[j] = x;
			permutation(word, i + 1);
		}

	}
	else
	cout << endl << word;
}


int main()
{
	string word;
	cout << "Enter word: " << endl;
	getline(cin, word);
	cout << endl << "The permutations are: ";
	//Start permutation
	permutation(word,0);
	getchar();

}