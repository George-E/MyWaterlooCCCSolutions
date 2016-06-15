#include <iostream>
//#include <string>
#include <vector>
//#include <sstream>
//#include <algorithm>
#include <cmath>

using namespace std;

bool check(int x, int y, int M) {
	if (y < pow(5, M - 1) && x >= pow(5, M - 1) && x < 4* pow(5, M - 1))
		return true;
	else if (y < 2 * pow(5, M - 1) && x >= 2 * pow(5, M - 1) && x < 3 * pow(5, M - 1))
		return true;
	else if (M > 1) {
		if (x >= pow(5, M - 1) && x< 2 * pow(5, M - 1)) {
			x -= pow(5, M - 1);
			y -= pow(5, M - 1);
			M--;
			return check(x, y, M);
		}
		else if (x < 3 * pow(5, M - 1) && x >= 2 * pow(5, M - 1)) {
			x -= 2 * pow(5, M - 1);
			y -= 2*pow(5, M - 1);
			M--;
			return check(x, y, M);
		}
		else if (x < 4* pow(5, M - 1) && x >= 3 * pow(5, M - 1)) {
			x -= 3 * pow(5, M - 1);
			y -= pow(5, M - 1);
			M--;
			return check(x, y, M);
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int M, x, y;
		cin >> M >> x >> y;
		if (check(x,y,M))
			cout << "crystal" << endl;
		else 
			cout << "empty" << endl;
	}
	//system("pause");//remove
}