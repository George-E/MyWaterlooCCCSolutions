#include <iostream>
#include <string>
#include <vector>
//#include <sstream>
#include <algorithm>
//#include <cmath>

using namespace std;


int main()
{

	int M;
	cin >> M;

	vector<string> wallNames;
	vector<vector<int>> pensConnected;
	vector<int> costs;


	for (int i = 0; i < M; i++) {
		int E;
		cin >> E;

		vector<int> corners;
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


		for (int p = 0; p < E; p++) {
			int n = corners[p];
			int n2 = (p==E-1)? corners[0] : corners[p + 1];
			string name = (n<n2) ? (to_string(n) + to_string(n2)) : (to_string(n2) + to_string(n)) ;

			int pos = find(wallNames.begin(), wallNames.end(), name) - wallNames.begin();
			if (pos >= wallNames.size()) {
				//not found
				wallNames.push_back(name);
				costs.push_back(prices[p]);
				vector<int> pens;
				pens.push_back(i);
				pensConnected.push_back(pens);
			}
			else {
				pensConnected[pos].push_back(i);
			}
		}
	}

	vector<vector<int>> adjacencyMatrix;
	//set up matrix
	//last element (M) is for outside
	vector<int> line(M + 1, -1); //creates vector with M+1 elements with value -1 (represents not connected)
	for (int i = 0; i < M+1; i++) {
		adjacencyMatrix.push_back(line);
		//adjacencyMatrix[i][i] = 0; 
	}
	for (int i = 0; i < pensConnected.size(); i++) {
		if (pensConnected[i].size() == 2) {
			int n = pensConnected[i][0];
			int n2 = pensConnected[i][1];
			if (adjacencyMatrix[n][n2] == -1 || adjacencyMatrix[n][n2] > costs[i]) { //b/c theyre might be two edges between pens
				adjacencyMatrix[n][n2] = costs[i];
				adjacencyMatrix[n2][n] = costs[i];
			}
		}
		else {
			int n = pensConnected[i][0];
			if (adjacencyMatrix[n][M] == -1 || adjacencyMatrix[n][M] > costs[i]) {
				adjacencyMatrix[n][M] = costs[i];
				adjacencyMatrix[M][n] = costs[i];
			}
		}
	}


	/*for (int i = 0; i < M + 1; i++){
		for (int k = 0; k < M + 1; k++){
			cout << adjacencyMatrix[i][k] << "\t";
		}
		cout << endl;
	}//remove*/

	//use Prim's algorithm to solve Minimal Spanning Tree (MST) for a weighted undirected graph through use of an adjecency matrix
	//first step is to pick an arbitrary vertex : 0;
	//then keep taking the minimum weighted path from a attached vertex to an unattached vertex
	//stop when all vertices are attached
	
	int totalCost = 0;
	bool attached[101]{};
	attached[0] = true;

	int min;
	int v = 0;
	for (int counter = 1; counter < ((attached[M]) ? M +1 : M); counter++){//numVertices - 1 (amt need starter needs to reach)

		min = 5001; //(max cost is 5000)

		for (int i = 0; i < M + 1; i++){
			if (attached[i]){
				for (int j = 0; j < M + 1; j++){
					if (!attached[j]){
						if (adjacencyMatrix[i][j] != -1 && min > adjacencyMatrix[i][j]){

							min = adjacencyMatrix[i][j];
							v = j;

						}

					}

				}

			}

		}
		attached[v] = true;
		totalCost += min;
	}

	cout << totalCost;

	system("pause");//remove
}