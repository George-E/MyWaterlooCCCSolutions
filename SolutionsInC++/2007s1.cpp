#include <iostream>
#include <string>
//#include <vector>
//#include <sstream>
//#include <algorithm>
//#include <cmath>

using namespace std;

//18 years before voting day 1989 2 27

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int year, month, day;
		cin >> year >> month >> day;

		if (year > 1989) 
			cout << "No" << endl;
		else if (year < 1989) 
			cout << "Yes" << endl;
		else
			if (month > 2)
				cout << "No" << endl;
			else if (month < 2)
				cout << "Yes" << endl;
			else
				if (day > 27)
					cout << "No" << endl;
				else 
					cout << "Yes" << endl;
	}
	system("pause");//remove
}

