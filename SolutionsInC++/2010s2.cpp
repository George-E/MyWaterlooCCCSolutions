#include <iostream>
#include <string>
#include <vector>
//#include <sstream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	int k;
	cin >> k;
	string chars; //unlike java, dont have to inititialize t append strings to
	vector<string> bytes;
	int maxlength = 0;

	for (int i = 0; i < k; i++) {
		string character, code;
		cin >> character >> code;
		chars += character;
		bytes.push_back(code);
		if (code.length() > maxlength)
			maxlength = code.length();
	}

	string answer;
	string line;
	cin >> line;
	int counter = 0;
	int length = line.length();
	while (counter < length) {
		for (int i = 1; i <= maxlength; i++) {
			int pos = find(bytes.begin(), bytes.end(), line.substr(counter, i)) - bytes.begin();
			if (pos < bytes.size()) { //found.. be sure not to use <=, as >= is for not found
				counter += i;
				answer += chars[pos];
				break;
			}
		}
	}

	cout << answer << endl;
	//system("pause");//remove
}