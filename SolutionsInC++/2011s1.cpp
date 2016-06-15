#include <iostream>
#include <string>
//#include <vector>
#include <sstream>
#include <algorithm>
//#include <cmath>

using namespace std;

int main()
{
	string line;
	getline(cin, line);
	int N;
	stringstream(line) >> N;

	int s=0, S=0, t=0, T=0;
	for (int i = 0; i < N; i++) {
		getline(cin, line);
		s += count(line.begin(), line.end(), 's');
		S += count(line.begin(), line.end(), 'S');
		t += count(line.begin(), line.end(), 't');
		T += count(line.begin(), line.end(), 'T');
	}

	if (s + S < t + T)
		cout << "English" << endl;
	else
		cout << "French" << endl;

	//system("pause");//remove
}