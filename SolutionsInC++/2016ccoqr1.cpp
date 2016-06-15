#include <iostream>
#include <string>
#include <vector>
//#include <sstream>
#include <algorithm>
//#include <cmath>
#include <map>
using namespace std;


int main()
{
	int numberC;
	cin >> numberC;

	vector<long> xs;
	vector<vector<long>> ysWithX;
	vector<long> ys;
	vector<vector<long>> xsWithy;

	for (int i = 0; i < numberC; i++) {
		long x, y;
		cin >> x >> y;
		int pos = find(xs.begin(), xs.end(), x) - xs.begin();
		if (pos < xs.size()) {
			ysWithX[pos].push_back(y);
		}
		else {
			xs.push_back(x);
			vector<long> newYs(1, y);
			ysWithX.push_back(newYs);
		}

		pos = find(ys.begin(), ys.end(), y) - ys.begin();
		if (pos < ys.size()) {
			xsWithy[pos].push_back(x);
		}
		else {
			ys.push_back(y);
			vector<long> newXs(1, x);
			xsWithy.push_back(newXs);
		}
	}

	//sort(xs.begin(), xs.end());

	long long count = 0;

	for (int a = 0; a < ys.size(); a++) {
		sort(xsWithy[a].begin(), xsWithy[a].end());
		/*cout << ys[a] << endl;
		for (int b = 0; b < xsWithy[a].size(); b++) {
			cout << xsWithy[a][b] << " ";
		}
		cout << endl;*/
	}

	for (int a = 0; a < xs.size(); a++) {
		if (ysWithX[a].size() > 2) {
			sort(ysWithX[a].begin(), ysWithX[a].end());
			for (int b = 1; b < ysWithX[a].size() - 1; b++) {
				long long beforeY = b;
				long long afterY = ysWithX[a].size() - 1 - b;

				long long x = xs[a];
				long long y = ysWithX[a][b];

				long long ypos = find(ys.begin(), ys.end(), y) - ys.begin();
				long long xpos = find(xsWithy[ypos].begin(), xsWithy[ypos].end(), x) - xsWithy[ypos].begin();
				
				long long beforeX = xpos;
				long long afterX = xsWithy[ypos].size() - 1 - xpos;

				count += (long long)beforeY * afterY * beforeX * afterX * 2;
			}
		}
	}

	cout << count << endl;

	//system("pause");//remove
}
