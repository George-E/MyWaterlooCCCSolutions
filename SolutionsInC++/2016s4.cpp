#include <iostream>
#include <string>
#include <vector>
//#include <sstream>
#include <algorithm>
//#include <cmath>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> starterRb;
	for (int i = 0; i < N; i++) {
		int b;
		cin >> b;
		starterRb.push_back(b);
	}

	vector<vector<int>> rb;
	rb.push_back(starterRb);

	int max = 0;

	while (rb.size() >0) {

		/*for (int i = 0; i < rb[0].size(); i++) {
			cout << " " << rb[0][i];
		}//remove
		cout << endl;//remove*/

		/*if (rb[0].size() == 1) {
			cout << rb[0][0] << endl;
			return 0;
		}*/

		
		bool test = true;
		for (int i = 0; i < rb[0].size()-1; i++) {
			if (rb[0][i] == rb[0][i + 1]) {
				vector<int> s = rb[0];
				s[i + 1] *= 2;
				s.erase(s.begin() + i);

				//
				int pos = find(rb.begin(), rb.end(), s) - rb.begin();
				if (pos >= rb.size()) {
					//not found
					rb.push_back(s);
				}
				//

				//rb.push_back(s);
				test = false;
			}
			if (i < rb[0].size() - 2 && rb[0][i] == rb[0][i + 2]) {
				vector<int> s = rb[0];
				s[i + 2] *= 2;
				s[i + 2] += s[i + 1];
				s.erase(s.begin() + i);
				s.erase(s.begin() + i); //i +1 becomes i
				
				//
				int pos = find(rb.begin(), rb.end(), s) - rb.begin();
				if (pos >= rb.size()) {
					//not found
					rb.push_back(s);
				}
				//
				
				//rb.push_back(s);
				test = false;
			}
		}
		if (test) {
			for (int i = 0; i < rb[0].size() ; i++) {
				if (rb[0][i] > max)
					max = rb[0][i];
			}
		}
		rb.erase(rb.begin());
	}

	cout << max << endl;
	//system("pause");//remove
}