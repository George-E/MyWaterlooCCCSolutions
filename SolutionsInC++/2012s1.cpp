#include <iostream>
#include <string>
//#include <vector>
//#include <sstream>
//#include <algorithm>
//#include <cmath>

using namespace std;

int main()
{
	int J;
	cin >> J;
	int answer = 0;
	for (int i = J - 1; i > 2; i--) {
		for (int t = i - 1; t > 1; t--) {
			for (int p = t - 1; p > 0; p--) {
				answer++;
			}
		}
	}
	cout << answer << endl;

	//system("pause");//remove
}