#include <iostream>
#include <string>
#include <vector>
//#include <sstream>
//#include <algorithm>
//#include <cmath>

using namespace std;

int main()
{
	int R, C;
	cin >> R >> C;

	vector<vector<int>> lab;
	for (int i = 0; i < R + 1; i++) {
		vector<int> line(C + 1);
		lab.push_back(line);
	}

	vector<vector<bool>> labDone;
	for (int i = 0; i < R + 1; i++) {
		vector<bool> line(C + 1, true);
		labDone.push_back(line);
	}

	int K;
	cin >> K;

	for (int i = 0; i < K; i++) {
		int x, y;
		cin >> x >> y;
		labDone[x][y] = false;
	}

	lab[1][1] = 1;
	labDone[1][1] = false;

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (labDone[i][j])
				lab[i][j] = lab[i][j - 1] + lab[i - 1][j];
		}
	}

	cout << lab[R][C] << endl;
	//system("pause");//remove
}