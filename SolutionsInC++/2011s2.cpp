#include <iostream>
//#include <string>
#include <vector>
//#include <sstream>
//#include <algorithm>
//#include <cmath>

using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<char> students;
	for (int i = 0; i < N; i++) {
		char c;
		cin >> c;
		students.push_back(c);
	}
	int count = 0;
	for (int i = 0; i < N; i++) {
		char c;
		cin >> c;
		if (c == students[i])
			count++;
	}
	cout << count << endl;
	//system("pause");//remove
}