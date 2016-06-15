


////////////////////////////////

//THIS CODE DOES NOT WORK
//GO TO 2014s4 FOR CORRECTED VERSION

////////////////////////////////




#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

vector<string> walls;
vector<int> costs;
vector<vector<int>> pensConnected;
vector<vector<int>> wallsConnected;
vector<bool> outsideWalls;

vector<int> accesiblepens;
vector<int> masterdestroyedpens;
bool checkedOutside = false;


void checkPen(int index); //"forward declaration", so checkwall can call checkpen

void checkWall(int index) {
	for (int h = 0; h < pensConnected[index].size(); h++) {
		for (int r = 0; r < accesiblepens.size(); r++) {
			if (accesiblepens[r] == wallsConnected[index][h]) {
				accesiblepens.push_back(h);
				checkPen(h);
			}
		}
	}
}

void checkOutside() {
	for (int h = 0; h < outsideWalls.size(); h++) {
		if (outsideWalls[h]) {
			for (int r = 0; r < masterdestroyedpens.size(); r++) {
				if (masterdestroyedpens[r] == h)
					checkWall(h);
			}
		}
	}
}

void checkPen(int index) {
	for (int h = 0; h < wallsConnected[0].size(); h++) {
		for (int r = 0; r < masterdestroyedpens.size(); r++) {
			if (masterdestroyedpens[r] == wallsConnected[index][h])
				checkWall(wallsConnected[index][h]);
			if (outsideWalls[wallsConnected[index][h]]) {
				checkOutside();
				checkedOutside = true;
			}
		}
	}
}


int main(){
	int M;
	cin >> M;

	for (int i = 0; i < M; i++) {
		int E;
		cin >> E;

		vector<int> corners; 
		//(cant decleare array or array<> with variable as size)
		for (int n = 0; n < E; n++) {
			int c;
			cin >> c;
			corners.push_back(c);
		}
		vector<int> prices; 
		for (int n = 0; n < E; n++) {
			int c;
			cin >> c;
			prices.push_back(c);
		}

		vector<int> wallsonpen;

		int counter = 0;
		for (int n = 0; n < E-1; n++) {
			for (int n2 = n+1; n2 < E ; n2 ++) {

				string name = to_string(n) + to_string(n2);

				int pos = find(walls.begin(), walls.end(), name) - walls.begin();
				if (pos >= walls.size()) {
					//not found
					walls.push_back(name);
					costs.push_back(prices[counter]);
					vector<int> pens;
					pens.push_back(i);
					pensConnected.push_back(pens);

					wallsonpen.push_back(walls.size()-1);
				}
				else {
					pensConnected[pos].push_back(i);
					wallsonpen.push_back(pos);
				}
				counter++;
			}
		}

		wallsConnected.push_back(wallsonpen);
	}

	int numWalls = walls.size();

	for (int w = 0; w < numWalls; w++) {
		if (pensConnected[w].size() > 1)
			outsideWalls.push_back(false);
		else
			outsideWalls.push_back(true);
	}

	int bestcost = 100000;

	vector<vector<int>> pensDestroyed;
	vector<int> costSoFar;

	vector<int> pens;
	pensDestroyed.push_back(pens);
	costSoFar.push_back(0);

	while (pensDestroyed.size() > 0) {

		if (pensDestroyed[0].size() > M-2) { //check if finished
			accesiblepens.clear();
			accesiblepens.push_back(0);
			masterdestroyedpens = pensDestroyed[0];
			checkPen(0);
			if (accesiblepens.size() + ((checkedOutside)?1:0) == M+1) {
				if (costSoFar[0] < bestcost) {
					bestcost = costSoFar[0];
				}
				pensDestroyed.erase(pensDestroyed.begin());
				costSoFar.erase(costSoFar.begin());
				continue;
			}
		}

		int maxsofar = -1;
		if (pensDestroyed[0].size() > 0)  {
			maxsofar = pensDestroyed[0].back(); //returns last element
			if (maxsofar == numWalls - 1) {
				pensDestroyed.erase(pensDestroyed.begin());
				costSoFar.erase(costSoFar.begin());
				continue;
			}
		}

		for (int y = maxsofar + 1; y < numWalls; y++) {
			int newcost = costSoFar[0] + costs[y];
			if (newcost < bestcost) {
				vector<int> newdestroyed = pensDestroyed[0]; //if not work, check if this copies or reference
				newdestroyed.push_back(y);
				pensDestroyed.push_back(newdestroyed);
				costSoFar.push_back(newcost);
			}
		}
		pensDestroyed.erase(pensDestroyed.begin());
		costSoFar.erase(costSoFar.begin());
	}

	cout << bestcost;
	system("pause");//remove
}