#include <iostream>
#include <string>
#include <vector>
//#include <sstream>
#include <algorithm>
#include <cmath>

using namespace std;


int main()
{
	int T, N;
	cin >> T >>N;

	vector<int> Dcity;
	vector<int> Pcity;

	for (int i = 0; i < N; i++) {
		int r;
		cin >> r;
		Pcity.push_back(r);
	}

	for (int i = 0; i < N; i++) {
		int r;
		cin >> r;
		Dcity.push_back(r);
	}

	sort(Dcity.begin(), Dcity.end());
	sort(Pcity.begin(), Pcity.end());

	/*for (int i = 0; i < N; i++) {
		cout << Dcity[i] << "\t" << Pcity[i] <<endl;
	}*/

	int answer = 0;
	for (int i = 0; i < N; i++) {

		if (T == 1)
			answer += max(Dcity[i], Pcity[i]);
		else
			answer += max(Dcity[i], Pcity[N-i-1]);
	}
	cout << answer << endl;

	//system("pause");//remove
}