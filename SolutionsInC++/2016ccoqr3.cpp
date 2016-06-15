#include <iostream>
#include <string>
#include <vector>
//#include <sstream>
//#include <algorithm>
//#include <cmath>

using namespace std;

int findIntersection(int row, int size) {
	return (size - row + 1)*(size - row + 2) / 2;
}

int areaOfTri(int row, int size) {
	return (size - row + 1)*(size - row + 2) / 2;
}

int main()
{
	long N, M;
	cin >> N >> M;
	int total = 0;
	vector<pair<int, int>> points;
	for (int i = 0; i < M; i++) {
		int r, c;
		cin >> r >> c;
		points.push_back(make_pair(r, c));
		total += areaOfTri(r, N);
		for (int p = 0; p < i; p++) {

		}
	}
	cout << total << endl;
	system("pause");//remove
}
