#include <iostream>
#include <string>
//#include <vector>
//#include <sstream>
//#include <algorithm>
//#include <cmath>
#include <map>

using namespace std;

int main()
{
	string a, b;
	cin >> a >> b;

	int countA[26]{};

	if (a.length() != b.length()) {
		cout << "N" << endl;
		//system("pause");//remove
		return 0;
	}

	for (int i = 0; i < a.length(); i++) {
		countA[a[i]-'a'] += 1;
	}

	int ast = 0;
	for (int i = 0; i < b.length(); i++) {
		if (b[i] == '*')
			ast++;
		else
			countA[b[i]-'a'] -= 1;
	}

	for (int i = 0; i < 26; i++) {
		if (countA[i] < 0) {
			cout << "N" << endl;
			//system("pause");//remove
			return 0;
		}
		else if (countA[i] > 0) {
			ast -= countA[i];
		}
	}

	if (ast == 0) {
		cout << "A" << endl;
	}
	else {
		cout << "N" << endl;
	}

	//system("pause");//remove
}