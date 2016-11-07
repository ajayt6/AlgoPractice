#include <iostream>
#include <fstream>
#include <string>
#include <streambuf>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

void split(const string &s, char delim, vector<string> &elems) {
    stringstream ss;
    ss.str(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
}


vector<string> split(const string &s, char delim) {
    vector<string> elems;
    split(s, delim, elems);
    return elems;
}

int main() {
	// your code goes here
	/*cout<<"Going to read file\n";
	std::ifstream t("file.txt");*/
    int charCountArray[128];
    
    //std::string str((std::istreambuf_iterator<char>(t)),
      //           std::istreambuf_iterator<char>());
	int numLines = 0;
    std::string str;
    cin>>numLines;

	while (numLines >= 0)
	{
		getline(cin, str);
		numLines--;
		//vector<string> tokenLines = split(str, '\n');

		//for (std::string tokenLine : tokenLines)
		{
			
			//cout << "\nToken line in order is: " << tokenLine << "\n";
			
			vector<string> tokens = split(str, ' ');

			for (int i = 0; i < 128; i++)
				charCountArray[i] = 0;


			int i = 0;
			for (std::string token : tokens)
			{
				i++;
				cout << "The string is " << token << "\n";
				for (char& c : token)
				{
					if (i == 1 && charCountArray[c] == 0)
					{
						charCountArray[c] = -1;
					}
					else if (i > 1 && charCountArray[c] != -1)
					{
						charCountArray[c] = charCountArray[c] * (-1);
					}


				}


				/*cout << "charcount array after round " << i << " is:\n";
				for (int i = 0; i < 128; i++)
					cout << charCountArray[i];*/

				for (int i = 0; i < 128; i++)
				{
					if (charCountArray[i] < 0)
						charCountArray[i] = 1;
					else
						charCountArray[i] = 0;
				}
				cout << "\n";
			}

			//after processing all strings in a line
			for (int i = 48; i <= 57; i++)
			{
				if (charCountArray[i] == 1)
				{
					char character = i;
					cout << character;
				}
			}
			for (int i = 65; i <= 122; i++)
			{
				if (charCountArray[i] == 1)
				{
					char character = i;
					cout << character;
				}

			}
			cout << endl;

		}
	}
	getchar();
	
	return 0;
}
