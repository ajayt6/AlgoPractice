/*
https://leetcode.com/problems/reconstruct-itinerary/
This is colution only for the base case
*/

#include<vector>
#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

class Node
{
public:
	string value;
	Node * next;
	Node()
	{
		value = "";
		next = NULL;
	}
};


vector<pair<string, string>> tickets;// = ("MUC", "LHR"), ("JFK", "MUC"), ("SFO", "SJC"), ("LHR", "SFO") };

vector<string> findItinerary(vector<pair<string, string>> tickets) {
	unordered_map<string, pair<Node*, int>> airportMap;
	string a;
	vector<string> resultVector;
	Node *temp = NULL,*begin = NULL;
	for (auto i = tickets.begin(); i != tickets.end(); i++)
	{
		
		//cout << i->first << " " << i->second << endl;
		//First check if the airport is already there in the map
		
		
		
		if (airportMap.find(i->first) == airportMap.end())
		{
			temp = new Node;
			temp->value = i->first;
			airportMap[i->first].first = temp;
			airportMap[i->first].second = 0;
		}
		else
		{
			temp = airportMap[i->first].first;
		}

		if (airportMap.find(i->second) == airportMap.end())
		{
			temp->next = new Node;
			temp->next->value = i->second;
			airportMap[i->second].first = temp->next;
			airportMap[i->second].second = 1;
		}
		else
		{
			temp->next= airportMap[i->second].first;
		}
		
		if (i->first.compare("JFK") == 0)
			begin = temp;

	}
	if (begin != NULL)
	{
		temp = begin;
		while (temp != NULL)
		{
			resultVector.push_back(temp->value);
			temp = temp->next;
		}
		return resultVector;
		
	}
	else
	return{ "Invalid" };
}

int main()
{
	vector<string> result;
	tickets.push_back(pair<string,string>("MUC", "LHR"));
	tickets.push_back(pair<string, string>("JFK", "MUC"));
	tickets.push_back(pair<string, string>("SFO", "SJC"));
	tickets.push_back(pair<string, string>("LHR", "SFO"));

	result = findItinerary(tickets);
	cout << "The result is: " << endl;
	for (auto i : result)
	{
		cout << i << " ";
	}
	getchar();
	return 0;
}