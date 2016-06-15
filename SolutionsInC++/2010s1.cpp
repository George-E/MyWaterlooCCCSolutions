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
	vector<string> best;
	vector<string> secondbest;
	int bestscore = 0;
	int secondbestscore = 0;
	for (int i = 0; i < n; i++) {
		string name;
		int R, S, D;
		cin >> name >> R >> S >> D;
		int score = 2 * R + 3 * S + D;
		if (score > bestscore) {
			secondbestscore = bestscore;
			secondbest = best;
			best.clear();
			best.push_back(name);
			bestscore = score;
		}
		else if (score == bestscore) {
			best.push_back(name);
		}
		else if (score > secondbestscore) {
			secondbestscore = score;
			secondbest.clear();
			secondbest.push_back(name);
		}
		else if (score == secondbestscore) {
			secondbest.push_back(name);
		}
	}

	sort(best.begin(), best.end());
	sort(secondbest.begin(), secondbest.end());
	best.insert(best.end(), secondbest.begin(), secondbest.end());

	if (best.size() > 1) {
		cout << best[0] << endl << best[1] << endl;
	}
	else if (best.size() > 0) {
		cout << best[0] ;
	}
	//system("pause");//remove
}