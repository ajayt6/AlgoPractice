/*
This is trie insert and search

*/
#include<iostream>
#include<string>
#include<algorithm>
#define ALPHABET_SIZE 26
using namespace std;

class trieCustom
{
	trieCustom* children[ALPHABET_SIZE];
	bool isLeaf;
	bool deleteWordRecurse(int i, string inputString, trieCustom* currentNode)
	{
		bool flag = false;
		if (i == inputString.length() - 1)
		{
			//We are at last character of string

			//If its a leaf node, then check if it has any more children. If not then return true else false
			if (currentNode->isLeaf)
			{
				currentNode->isLeaf = false;
				for (int k = 0; k < ALPHABET_SIZE; k++)
				{
					if (currentNode->children[k] != NULL)
						return false;

				}
				return true;
			}
			else //If it's not a leaf node then return false
				return false;
			
		}

		if (currentNode->children[inputString[i+1] - 'a'] == NULL)
			return false;
		else
		{	
			flag = deleteWordRecurse(i + 1, inputString, currentNode->children[inputString[i+1] - 'a']);
			
			if (flag)
			{
				delete currentNode->children[inputString[i] - 'a'];
				currentNode->children[inputString[i] - 'a'] = NULL;
				if (currentNode->isLeaf)
					return false;
				else
					return true;
			}
			else
				return false;
		}
			
	}

public:

	trieCustom()
	{
		for (int i = 0; i < ALPHABET_SIZE; i++)
			children[i] = NULL;
		isLeaf = false;
	}
	void insert(string inputString)
	{
		//Frist transform the string to lowercase
		transform(inputString.begin(), inputString.end(), inputString.begin(), ::tolower);
		trieCustom* currentNode = this;
		for (int i = 0; i < inputString.length(); i++)
		{
			
			if (currentNode->children[inputString[i] - 'a'] == NULL)
			{
				currentNode->children[inputString[i] - 'a'] = new trieCustom();
				
			}

			currentNode = currentNode->children[inputString[i] - 'a'];
			if (i == inputString.length() - 1)
				currentNode->isLeaf = true;
		}

	}

	bool search(string inputString)
	{
		//Frist transform the string to lowercase
		transform(inputString.begin(), inputString.end(), inputString.begin(), ::tolower);
		
		trieCustom* currentNode = this;
		for (int i = 0; i < inputString.length(); i++)
		{
			
			if (currentNode->children[inputString[i] - 'a'] == NULL)
			{
				break;

			}

			currentNode = currentNode->children[inputString[i] - 'a'];
			if (i == inputString.length() - 1)
			{
				if (currentNode->isLeaf)
					return true;
			}
		}

		return false;
	}

	bool deleteWord(string inputString)
	{
		//Check if inputString is actually present
		if (!search(inputString))
			return false;

		//Frist transform the string to lowercase
		transform(inputString.begin(), inputString.end(), inputString.begin(), ::tolower);

		int i = 0;
		if (this->children[inputString[i] - 'a'] != NULL)
			return deleteWordRecurse(i, inputString, this->children[inputString[i] - 'a']);
		else
			return false;
	}
};

int main()
{
	trieCustom trie;
	string word;
	int choice, exitFlag =0;

	while (true)
	{
		cout << endl<<"1)Insert\n2)Search\n3)Delete\n4)Exit\nEnter Choice (1,2 or 3): ";
		cin >> choice;
		
		switch (choice)
		{
		case 1:
				cout << "\nEnter word you want to insert (Note: It should only contain alphabets): ";
				getchar();
				getline(cin, word);
				cout << endl << "The word is: " << word;
				trie.insert(word);//"helloTrie");
				break;
		case 2:
			cout << "Enter word you want to search (Note: It should only contain alphabets): ";
			getchar();
			getline(cin, word);
			cout << endl << "The word is: " << word;
			cout << endl<<"trie.search(\"" << word << "\") = " << trie.search(word)<<endl;
			break;
		case 3:
			cout << "Enter word you want to delete (Note: It should only contain alphabets): ";
			getchar();
			getline(cin, word);
			cout << endl << "trie.deleteWord(\"" << word << "\") = " << trie.deleteWord(word) << endl;
			break;
		case 4:
			exitFlag = 1;
			break;
		default:
			cout << "\nWrong choice";

		}
		if (exitFlag == 1)
			break;
	}
	
	getchar();
	return 0;
}