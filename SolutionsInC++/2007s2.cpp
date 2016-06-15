#include <iostream>
#include <string>
#include <vector>
//#include <sstream>
#include <algorithm>
//#include <cmath>

using namespace std;


int main()
{
	int n;
	cin >> n;
	vector<vector<int>> boxes;
	for (int i = 0; i < n; i++) {
		int l, h, w;
		cin >> l >> w >> h;
		vector<int> box;
		box.push_back(l);
		box.push_back(w);
		box.push_back(h);
		sort(box.begin(), box.end());
		box.push_back(l*w*h);
		boxes.push_back(box);
	}



	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int l, h, w;
		cin >> l >> w >> h;
		vector<int> box;
		box.push_back(l);
		box.push_back(w);
		box.push_back(h);
		sort(box.begin(), box.end());

		int min = -1;
		for (int b = 0; b < n; b++) {
			if (min == -1 || boxes[b][3] < min) {
				bool test = true;
				for (int d = 0; d < 3; d++) {
					if (box[d] > boxes[b][d])
						test = false;
				}
				if (test) {
					min = boxes[b][3];
					//cout << "\t" << b << endl;//remove
				}
			}
		}

		if (min == -1) {
			cout << "Item does not fit." << endl;
		}
		else {
			cout << min << endl;
		}
	}
	system("pause");//remove
}

