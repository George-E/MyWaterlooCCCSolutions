#include <iostream>
#include <string>
#include <vector>
//#include <sstream>
//#include <algorithm>
//#include <cmath>

using namespace std;

int main()
{
	long long N;
	long long T;
	cin >> N >> T;

	string lights;
	cin >> lights;

	/*
	for (int i = 0; i < T; i++) {
		string hold = lights;
		if (hold[N - 1] == '1'  ^ hold[1] == '1')
			lights[0] = '1';
		else
			lights[0] = '0';

		if (hold[N - 2] == '1'  ^ hold[0] == '1')
			lights[N-1] = '1';
		else
			lights[N-1] = '0';

		for (int i = 1; i < N-1; i++) {
			if (hold[i+1] == '1'  ^ hold[i-1] == '1')
				lights[i] = '1';
			else
				lights[i] = '0';
		}
	}

	cout << lights << endl;
	*/

	char * ptr;
	long parsed = strtol(lights.c_str(), &ptr, 2);


	system("pause");//remove
}