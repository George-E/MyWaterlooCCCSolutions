#include <iostream>
#include <string>
//#include <vector>
#include <sstream>
//#include <algorithm>
//#include <cmath>
#include <map>

using namespace std;

int main()
{
	map<char, int> legend;
	legend['I'] = 1;
	legend['V'] = 5;
	legend['X'] = 10;
	legend['L'] = 50;
	legend['C'] = 100;
	legend['D'] = 500;
	legend['M'] = 1000;

	string line;
	getline(cin, line);
	int total = 0;
	int counter = 0;
	while (counter < line.length()) {
		if (counter + 3 < line.length() && (legend[line[counter+1]] < legend[line[counter + 3]])) {
			total -= (line[counter] - '0') * legend[line[counter+1]];
		}
		else {
			total += (line[counter] - '0') * legend[line[counter+1]];
		}
		counter += 2;
	}
	cout << total << endl;
	//system("pause");//remove
}