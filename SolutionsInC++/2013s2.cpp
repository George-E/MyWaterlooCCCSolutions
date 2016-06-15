#include <iostream>
#include <string>
#include <sstream>

using namespace std;


int main()
{
	int W, N;
	cin >> W >> N;
	int bridge[] = { 0, 0, 0, 0 };
	int bridgeSum = 0;
	int i = 1;
	for (i = 1; i <= N; i++) {
		bridgeSum -= bridge[3];
		bridge[3] = bridge[2];
		bridge[2] = bridge[1];
		bridge[1] = bridge[0];
		cin >> bridge[0];
		bridgeSum += bridge[0];
		if (bridgeSum > W) {
			i--;
			break;
		}
	}
	cout << i << endl;
	system("pause");
}