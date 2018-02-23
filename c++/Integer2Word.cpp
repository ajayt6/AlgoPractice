/*
https://leetcode.com/problems/integer-to-english-words/
*/
#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;


string numberToWords(int num) {
	int numDigits = 0;
	int temp,rem,times,tempRem;
	string number = "";
	vector<int>numVector;
	unordered_map<int, string> posMap;
	unordered_map<int, string> posBaseMap;
	

	if (num == 0)
		return "Zero";
	//Init with relevant values
	posMap.insert(pair<int,string>(0,""));
	posMap.insert(pair<int, string>(1, "Thousand"));
	posMap.insert(pair<int, string>(2, "Million"));
	posMap.insert(pair<int, string>(3, "Billion"));

	posBaseMap.insert(pair<int, string>(0, ""));
	posBaseMap.insert(pair<int, string>(1, "One"));
	posBaseMap.insert(pair<int, string>(2, "Two"));
	posBaseMap.insert(pair<int, string>(3, "Three"));
	posBaseMap.insert(pair<int, string>(4, "Four"));
	posBaseMap.insert(pair<int, string>(5, "Five"));
	posBaseMap.insert(pair<int, string>(6, "Six"));
	posBaseMap.insert(pair<int, string>(7, "Seven"));
	posBaseMap.insert(pair<int, string>(8, "Eight"));
	posBaseMap.insert(pair<int, string>(9, "Nine"));

	posBaseMap.insert(pair<int, string>(10, "Ten"));
	posBaseMap.insert(pair<int, string>(11, "Eleven"));
	posBaseMap.insert(pair<int, string>(12, "Twelve"));
	posBaseMap.insert(pair<int, string>(13, "Thirteen"));
	posBaseMap.insert(pair<int, string>(14, "Fourteen"));
	posBaseMap.insert(pair<int, string>(15, "Fifteen"));
	posBaseMap.insert(pair<int, string>(16, "Sixteen"));
	posBaseMap.insert(pair<int, string>(17, "Seventeen"));
	posBaseMap.insert(pair<int, string>(18, "Eighteen"));
	posBaseMap.insert(pair<int, string>(19, "Nineteen"));

	posBaseMap.insert(pair<int, string>(20, "Twenty"));
	posBaseMap.insert(pair<int, string>(30, "Thirty"));
	posBaseMap.insert(pair<int, string>(40, "Forty"));
	posBaseMap.insert(pair<int, string>(50, "Fifty"));
	posBaseMap.insert(pair<int, string>(60, "Sixty"));
	posBaseMap.insert(pair<int, string>(70, "Seventy"));
	posBaseMap.insert(pair<int, string>(80, "Eighty"));
	posBaseMap.insert(pair<int, string>(90, "Ninety"));


	temp = num;
	while (temp != 0)
	{
		numDigits++;
		rem = temp % 10;
		temp = temp / 10;
		numVector.push_back(rem);
	}
	times = numDigits / 3;
	rem = numDigits % 3;
	tempRem = rem;
	if (rem == 0)
		times--;

	for (auto i = numVector.end() - 1; i>=numVector.begin(); i--)
	{
		while (*(i) == 0 && i >= numVector.begin())
			i--;

			//Form triplet
			if (i - 2 >= numVector.begin()  && tempRem == 0)
			{
				if(*(i-1) == 0 && *(i - 2) == 0)
					number = number.append(posBaseMap[*i]).append(" Hundred");
				else
				number = number.append(posBaseMap[*i]).append(" Hundred ");
				i--;
				tempRem = 2;
			}

			
			
			if (i - 1 >= numVector.begin() && tempRem ==2)
			{
				if (*(i) == 1)
					number = number.append(posBaseMap[*(i) * 10 + *(i - 1)]);
				else
				{	
					if (*(i - 1) != 0)
					{	
						if(*(i)==0)
							number = number.append(posBaseMap[*(i) * 10]).append(posBaseMap[*(i - 1)]);
						else
						number = number.append(posBaseMap[*(i) * 10]).append(" ").append(posBaseMap[*(i - 1)]);
					}
					else
						number = number.append(posBaseMap[*(i) * 10]);
				}
				i = i - 1;
				tempRem = 0;
			}
			else {
				number = number.append(posBaseMap[*(i)]);
				tempRem = 0;
			}
				
				
			
			
		
		
		/**/
		
		switch (times)
		{
		case 0:	
			break;
		case 1:
		case 2:
		case 3:
			number = number.append(" ").append(posMap[times]).append(" ");
			break;
		default:
			break;
		}
		times--;
		
	}
	if (number[number.length() - 1] == ' ')
		number = number.substr(0, number.length() - 1);

	return number;
}

int main()
{
	int n;
	cout << "Enter integer: ";
	cin >> n;
	cout << "The converted integer in words is: "<<numberToWords(n).c_str();
	getchar();
	getchar();

	return 0;
}