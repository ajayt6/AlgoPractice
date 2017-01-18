#include<iostream>
#include<queue>
#include<map>
#include<fstream>
#include<string>
using namespace std;

class Compare
{
public:
	bool operator() (pair< int, string > p1, pair< int, string > p2)
	{
		if (p1.first < p2.first)
			return true;
		else
			return false;
	}
};


	

void outputK(string filename, int k)
{
	//Open and read the file
	map<string, int> siteMap;
	//priority_queue<int, string> sitePQ;
	std::priority_queue<pair<int, string>, std::vector<pair< int, string >>, Compare> sitePQ;
	ifstream infile(filename);
	string site = "";

	if (!infile) {
		cout << "Cannot open input file.\n";
		return ;
	}

	while (infile >> site)
	{
		if (siteMap.find(site) != siteMap.end())
		{
			//Update it
			siteMap[site]++;
		}
		else
		{
			//Insert site
			siteMap.insert(pair<string, int>(site, 1));
			
		}

	}
	infile.close();

	//Now put all into priority Q
	for (auto i = siteMap.begin(); i != siteMap.end(); i++)
	{
		sitePQ.push(pair<int, string>(i->second, i->first));

	}

	//Now print the k most common sites
	while (sitePQ.size()>0 &&  k > 0)
	{
		cout << sitePQ.top().second << endl;
		k--;
		sitePQ.pop();
	}

	return;
}

int main()
{
	int k;
	cout << "Enter the value of k: ";
	cin >> k;
	outputK("test.txt",k);
	getchar();
	getchar();
	return 0;
}