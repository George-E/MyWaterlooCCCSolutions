#include <iostream>
//#include <string>
#include <vector>
//#include <sstream>
//#include <algorithm>
#include <cmath>

using namespace std;

//can't be 8 on together as no group of 4 exists by itself)
string turnOffSeq(string x) {

	size_t seq = x.find("1111111");
	if (seq != string::npos)
		x = x.replace(seq, 7, "0000000");
	seq = x.find("111111");
	if (seq != string::npos)
		x = x.replace(seq, 6, "000000");
	seq = x.find("11111");
	if (seq != string::npos)
		x = x.replace(seq, 5, "00000");
	seq = x.find("1111");
	if (seq != string::npos)
		x = x.replace(seq, 4, "0000");
	return x;
}

int main()
{
	int T;
	cin >> T;
	
	string starter = "";
	for (int i = 0; i < T; i++) {
		char c;
		cin >> c;
		starter += c;
	}

	vector < string > lights;
	vector < int > count;
	lights.push_back(starter);
	count.push_back(0);
	int minCount = 100000;

	while (lights.size() >0) {
		if (lights[0].find("1") == string::npos) {
			if (minCount > count[0])
				minCount = count[0];
			lights.erase(lights.begin());
			count.erase(count.begin());
			continue;
		}
		else if (count[0] >= minCount) {
			lights.erase(lights.begin());
			count.erase(count.begin());
			continue;
		}
		for (int i = 0; i < T; i++) {
			if (lights[0][i] == '0') {
				string lightStart = lights[0];
				lightStart[i] = '1';
				lightStart = turnOffSeq(lightStart);
				lights.push_back(lightStart);
				count.push_back(count[0]+1);
			}
		}
		lights.erase(lights.begin());
		count.erase(count.begin());
	}

	cout << minCount << endl;

	//system("pause");//remove
}