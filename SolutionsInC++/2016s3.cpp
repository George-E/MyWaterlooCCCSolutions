#include <iostream>
#include <string>
#include <vector>
//#include <sstream>
#include <algorithm>
//#include <cmath>

using namespace std;


vector<vector<int>> adjList;
vector<int> irrelevent;

pair<int,int> timeFromHere(int start, int prev) {
	int total = 0;
	int maxDistToEnd = 0;
	/*int numPart;if (prev == -1)
	numPart = 1;
	else
	numPart = adjList[start].size() - 1;*/

	int counter = 0;
	vector<int> maxpaths;
	for (int i = 0; i < adjList[start].size(); i++) {
		if (adjList[start][i] != prev && !irrelevent[adjList[start][i]]) {
			pair<int, int> y = timeFromHere(adjList[start][i], start);
			total += y.first;
			maxpaths.push_back(y.second);
			counter++;
		}
	}

	if (counter == 0) {

		cout << start << " 1 1" << endl;//remove
		return make_pair(1, 1);

		
	}
	else if (counter == 1) {

		cout << start << " " << (1 + total) << " " << (1 + maxpaths[0]) << endl;//remove
		return make_pair(1 + total, 1 + maxpaths[0]);
	}
	else  {
		sort(maxpaths.begin(), maxpaths.end());
		cout << start << " " << (1 + total) << " " << (1 + maxpaths[counter-1]) << endl;//remove
		return make_pair(1 + total, 1 + maxpaths[counter - 1]);
	}
}

int main()
{
	int N, M;
	cin >> N >> M;

	vector<bool> isPho(N, false);
	for (int i = 0; i < M; i++) {
		int p;
		cin >> p;
		isPho[p] = true;
	}

	for (int i = 0; i < N; i++) {
		vector<int> adj;
		adjList.push_back(adj);
		irrelevent.push_back(false);
	}

	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		adjList[a].push_back(b);
		adjList[b].push_back(a);
	}


	for (int i = 0; i < N; i++) { //erases irrelvent restaurants
		if (!isPho[i] && !irrelevent[i]) {
			int count = 0;
			for (int q = 0; q < adjList[i].size(); q++) {
				if (!irrelevent[adjList[i][q]]) {
					count++;
				}
			}
			//cout << i << " " << count << endl;//remove
			if (count < 2) {
				irrelevent[i] = true;
				i = 0;
			}
		}
	}

	//find place to start.. 1 path
	vector <int> starter;
	for (int i = 0; i < N; i++) {
		if (isPho[i]) {
			int count = 0;
			for (int q = 0; q < adjList[i].size(); q++) {
				if (!irrelevent[adjList[i][q]]) {
					count++;
				}
			}
			if (count == 1) {
				starter.push_back(i);
			}
		}
	}

	int min = -1;
	for (int i = 0; i < starter.size(); i++) {
		//if (!irrelevent[i]) {
			pair<int, int>  h = timeFromHere(starter[i], -1);
			if (min == -1 || min > -1 + h.second + 2 * (h.first - h.second))
				min = -1 + h.second + 2 * (h.first - h.second);
		//}
	}

	cout << min << endl;

	system("pause");//remove
}