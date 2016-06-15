#include <iostream>
#include <string>
#include <vector>
//#include <sstream>
//#include <algorithm>
//#include <cmath>

using namespace std;


int main()
{
	int n;
	cin >> n;
	
	vector<int> empty;
	vector<vector<int>> sources(n,empty);

	int a, b;
	cin >> a >> b;
	while (!(a == 0 && b == 0)) {
		sources[b - 1].push_back(a-1);
		cin >> a >> b;
	}

	vector<int> count(n, 0);
	count[n - 1] = 1;

	for (int i = n-1; i > 0; i--) {
		for each (int s in sources[i]) {
			count[s] += count[i];
		}
	}

	cout << count[0] << endl;
	system("pause");//remove
}

