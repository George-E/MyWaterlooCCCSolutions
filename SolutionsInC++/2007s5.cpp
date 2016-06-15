#include <iostream>
//#include <string>
#include <vector>
//#include <sstream>
//#include <algorithm>
//#include <cmath>

using namespace std;


int main()
{
	int testCases;
	cin >> testCases;
	for (int testC = 0; testC < testCases; testC++) {
		int pins, balls, width;
		cin >> pins >> balls >> width;
		vector<int> pinNumbers;
		for (int i = 0; i < pins; i++) {
			int pin;
			cin >> pin;
			pinNumbers.push_back(pin);
		}

		int max = 0;

		for (int space = 0; space < width; space++) {
			vector<int> top(balls, 0);



			int sum = 0;
			for (int l = 0; l < balls; l++)
				sum += top[l];
			if (sum > max)
				max = sum;
		}

		cout << max << endl;
	}
	system("pause");//remove
}

