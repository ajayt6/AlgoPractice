#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	
	map<string, int> colorMap;
	map<int, string> colorMapR;
	//colorMap = new map<string, int>;
	colorMap.insert(pair<string, int>("blank", 0));
	colorMap.insert(pair<string,int>("red", 1));
	colorMap.insert(pair<string, int>("blue", 2));
	colorMap.insert(pair<string, int>("yellow", 4));
	colorMap.insert(pair<string, int>("orange", 5)); //yellow + red
	colorMap.insert(pair<string, int>("green", 6));  // yellow + blue
	colorMap.insert(pair<string, int>("purple", 3)); //red + blue
	
	//colorMpaReverse
	colorMapR.insert(pair<int, string>( 0, "blank"));
	colorMapR.insert(pair<int, string>(1, "red"));
	colorMapR.insert(pair<int, string>(2, "blue"));
	colorMapR.insert(pair<int, string>(4, "yellow"));
	colorMapR.insert(pair<int, string>(5, "orange"));
	colorMapR.insert(pair<int, string>(6, "green"));
	colorMapR.insert(pair<int, string>(3, "purple"));

	string inputLine="";
	cout << "Enter the line of colours\n";
	getline(cin, inputLine);
	int colorLength = count(inputLine.begin(), inputLine.end(), ' ')+1;
	//split sentence into individual colors
	stringstream ss(inputLine);
	string color,prevcolor="";
	vector<string> colors;
	cout << endl;

	
	getline(ss, color, ' ');
	cout << color << " ";
	prevcolor = color;

	while (getline(ss, color, ' '))
	{
		colorLength--;
		if (!colorLength)
			continue;
		/*if ( (colorMap[color] <= 2 || colorMap[color] == 4) && (color.compare(prevcolor) != 0) )
		{
			cout << color << " ";
			prevcolor = color;
		}
		else*/
		{
			int colorNum = colorMap[color] - colorMap[prevcolor];
			cout << colorMapR[colorNum] << " ";
			prevcolor = colorMapR[colorNum];
		}
	}
	//colors.push_back(color);

	getchar();
	//for (string )
	return 0;
}