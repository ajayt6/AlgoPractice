#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
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
    
    cout<<"Enter input";
    int n;
    cin>>n;
    //cout<<"\nvalue of n is "<<n<<"\n";
    string inputLine;
    while (n>0)
    {
        cout<<"\nError checking";
        //getline(cin,inputLine);
        cout<<"\nfirst line is "<<inputLine;
        vector<string> numbers = split(inputLine,' ');
        int first = atoi(numbers.front().c_str());
        int last = atoi(numbers.back().c_str());
        for(int i=first;i<last;i++)
        {
            string findString = to_string(i);
            if( ! (find(numbers.begin(),numbers.end(),findString) != numbers.end()) )
            cout<<findString<<"";
        }
        n--; 
    }
	// your code goes here
	return 0;
}
