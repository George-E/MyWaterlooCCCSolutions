#include <iostream>
#include <string>
#include <sstream>

using namespace std;


int main()
{
	int year;
	string yearS;
	cin >> year;
	
	while (true) {
		year++;
		yearS = to_string(year); 
		//note that string blah = "" + intvar; doesnt work in c++
		//either do the above of put int into a stringstream and then string = ssstream.str();
		/*if (yearS.length() == 1) {
			break;
		}*/
		bool test = true;
		for (int i = 0; i < (int)yearS.length()-1; i++) {
			
			if (yearS.find(yearS[i], i + 1) != string::npos) {
				test = false;
				break;
			}
		}
		if (test) break;
	}
	cout << year <<endl;
	system("pause");
}