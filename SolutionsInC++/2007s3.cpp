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
	int n;
	cin >> n;
	vector<pair<int, int>> friends;
	map<int, int> indexOfStudentNumber;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		friends.push_back(make_pair(a, b));
		indexOfStudentNumber[a] = i;
	}

	vector<vector<int>> circles;
	int count = 0;
	while (friends.size() - count > 0) {
		vector<int> newcircle;

		int y;
		for (y = 0; y < n; y++) {
			if (friends[y].first != -1)
				break;
		}
		//cout << "\t" << y << endl;

		int starter = friends[y].first;
		int index = y;
		while (true) {
			newcircle.push_back(friends[index].first);
			//cout << friends[index].first << endl;
			friends[index].first = -1;
			count++;
			if (friends[index].second == starter)
				break;
			index = indexOfStudentNumber[friends[index].second];
		}
		circles.push_back(newcircle);
	}

	//remove
	/*for (int i = 0; i < circles.size(); i++) {
		for (int n = 0; n < circles[i].size(); n++) {
		cout << circles[i][n] << " ";
		}
		cout << endl;
		}*/

	int a, b;
	do {
		cin >> a >> b;
		for (int i = 0; i < circles.size(); i++) {
			int pos = find(circles[i].begin(), circles[i].end(), a) - circles[i].begin();
			if (pos < circles[i].size()) {//found
				int pos2 = find(circles[i].begin(), circles[i].end(), b) - circles[i].begin();
				if (pos2 >= circles[i].size()) {//not found
					cout << "No" << endl;
				}
				else if (pos < pos2){
					cout << "Yes" << (pos2-pos-1) << endl;
				}
				else {
					cout << "Yes" << (circles[i].size() -pos - 1 + pos2) << endl;
				}
				break;
			}
		}

	} while (a + b != 0);

	system("pause");//remove
}
