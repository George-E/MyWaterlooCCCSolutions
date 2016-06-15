#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <array>

using namespace std;

/*class arrayholder {
	public:
	bool *games[4]; 
	int *scores[4];
	arrayholder(bool g[], int s[]);
};

arrayholder::arrayholder(bool g[], int s[]) {
	*games = &g;
	*scores = &s;
}*/

vector<array<int,4>> scores; 
vector<array<bool, 6>> games;

int possibleWins = 0;


void updateScores(int A, int B) {
	scores[0][A] += 3;
	scores.push_back(scores[0]);
	games.push_back(games[0]);
	scores[0][A] -= 3;
	scores[0][B] += 3;
	scores.push_back(scores[0]);
	games.push_back(games[0]);
	scores[0][B] -= 2;
	scores[0][A] += 1;
	scores.push_back(scores[0]);
	games.push_back(games[0]);
}

int main()
{
	
	int T, G;
	cin >> T >>G;
	array<bool, 6> starterGames = {};
	array<int, 4> starterScores = {};

	for (int i = 0; i < G; i++) {
		int A, B, SA, SB;
		cin >> A >> B >> SA >> SB;

		switch (A) {
		case 1:
			switch (B) {
			case 2:
				starterGames[0] = true;
				break;
			case 3:
				starterGames[1] = true;
				break;
			case 4:
				starterGames[2] = true;
			}
			break;
		case 2:
			switch (B) {
			case 3:
				starterGames[3] = true;
				break;
			case 4:
				starterGames[4] = true;
			}
			break;
		case 3:
			starterGames[5] = true;
		}

		if (SA > SB) {
			starterScores[A - 1] += 3;
		}
		else if (SB > SA) {
			starterScores[B - 1] += 3;
		}
		else {
			starterScores[A - 1] += 1;
			starterScores[B - 1] += 1;
		}
	}

	scores.push_back(starterScores);
	games.push_back(starterGames);
	
	while (scores.size() > 0) {
		if (games[0][0] == 0) {
			games[0][0] = 1;
			updateScores(0, 1);
		}
		else if (games[0][1] == 0) {
			games[0][1] = 1;
			updateScores(0, 2);
		}
		else if (games[0][2] == 0) {
			games[0][2] = 1;
			updateScores(0, 3);
		}
		else if (games[0][3] == 0) {
			games[0][3] = 1;
			updateScores(1, 2);
		}
		else if (games[0][4] == 0) {
			games[0][4] = 1;
			updateScores(1, 3);
		}
		else if (games[0][5] == 0) {
			games[0][5] = 1;
			updateScores(2, 3);
		}
		else {
			bool test = true;
			for (int i = 0; i < 4; i++) {
				if (i == T - 1) continue;
				if (scores[0][i] >= scores[0][T - 1]){
					test = false;
					break;
				}
			}
			if (test) {
				possibleWins++;
			}
		}
		games.erase(games.begin());
		scores.erase(scores.begin());
	}

	cout << possibleWins << endl;
	system("pause");
	
}

