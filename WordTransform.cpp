#include <iostream>
#include <string>
#include<unordered_map>
#include<unordered_set>
#include <queue>

using namespace std;

bool adjascentWords(string a, string b)
{
	int diff = 0;
	if (a.length() != b.length())
		return false;
	for (int i = 0; i < a.length(); i++)
		if (a[i] != b[i])
			diff++;
	    if (diff>1)
			return false;
	return true;
}

//Function to check if two words are adjascent(differ by only one character)
int main()
{
	int n,q;
	string word,source,target;
	unordered_set<string> dictionary;
	//Enter words into dictionary
	cout << "Enter number of words in dictionary" << endl;
	cin >> n;
	cout << "Enter number of queries: " << endl;
	cin >> q;
	cout << "Enter words to be inserted into dictionary: "<<endl;
	getchar();
	while (n > 0)
	{
		getline(cin, word);
		dictionary.insert(word);
		n--;
	}
	while (q > 0)
	{
		int transforms = 0;
		int foundFlag = 0;
		queue<string> bfsQueue;
		unordered_set<string> bfsSet;

		for (unordered_set<string>::iterator i = dictionary.begin(); i != dictionary.end(); i++)
			bfsSet.insert(*i);

		cout << "Enter source word" << endl;
		getline(cin, source);
		cout << "Enter target word" << endl;
		getline(cin, target);
		q--;

		//check if source and target are equal
		if (source.compare(target) == 0)
		{
			foundFlag = 1;
			transforms = 0;
		}
		else
		{
			//Do a BFS until target word is found
			if (dictionary.find(source) != dictionary.end() && dictionary.find(target) != dictionary.end())
			{
				bfsQueue.push(source);
				bfsSet.erase(source);

				while (!bfsQueue.empty())
				{
					source = bfsQueue.front();
					bfsQueue.pop();
					


					//start comparing with all other words in dictionary
					for (unordered_set<string>::iterator i = bfsSet.begin(); i != bfsSet.end(); i++)
					{
						if (adjascentWords(source, *i))
						{
							if (target.compare(*i) == 0)
							{
								foundFlag = 1;
								break;
							}
							bfsQueue.push(*i);
							bfsSet.erase(*i);
							
						}
					}
					//A level is over. So increment transforms
					transforms++;

					if (foundFlag == 1)
						break;
				}
				if (foundFlag == 0)
					transforms = -1;
			}
			else
				transforms = -1;
		}

		cout << endl<<"Number of required transforms is: "<<transforms<<endl;
		
	}
	

	getchar();
	return 0;
}