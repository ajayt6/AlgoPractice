#include<iostream>
#include<string>

using namespace std;

int main()
{
	string sentence,message,cipher;
	cout << "Enter infinite sequence of lines" << endl;
	//getchar();

	while (1)
	{
		getline(cin, sentence);

		message = sentence.substr(0,sentence.find('|'));
		cipher = sentence.substr(sentence.find('|')+1, sentence.length());
		cout << endl << "The message is: " << message << " and the cipher is: " << cipher << endl;
		
		//begin transformations
		int ch;
		int j = 0;
		for (int i = 0; i < message.length(); i++)
		{
			if (message[i] >= 65 && message[i] <= 90)
			{
				ch = (message[i] - 65 + cipher[j%cipher.length()] - 65) % 26;
				message[i] = ch + 65;
				j++;
			}
			else if (message[i] >= 97 && message[i] <= 122)
			{
				ch = (message[i] - 97 + cipher[j%cipher.length()] - 65) % 26;
				message[i] = ch + 97;
				j++;
			}
			
		}
		cout << endl << "The encrypted message is: " << message;
		getchar();
	}

	return 0;
}