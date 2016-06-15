#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath> 

using namespace std;


int main(){
	string line;
	getline(cin, line);
	long N;
	stringstream(line) >> N;

	vector<int> readings;
	vector<int> freq;

	for (long i = 0; i < N; i++) {
		int read;
		cin >> read;
		int pos = find(readings.begin(), readings.end(), read) - readings.begin();
		if (pos >= readings.size()) {
			//not found
			readings.push_back(read);
			freq.push_back(1);
		}
		else {
			freq[pos]++;
		}
	}

	//testing
	/*for (long i = 0; i < readings.size(); i++) {
		cout << readings[i] << " " << freq[i] << endl;
	}
	cout << endl;*/

	long highestFreq = 0, highestFreqHighestVal = 0, highestFreqLowestVal = 2000001;
	long highestFreq2 = 0, highestFreqHighestVal2 = 0, highestFreqLowestVal2 = 2000001;

	for (long i = 0; i < readings.size(); i++) {

		//cout << readings[i] << " " << freq[i] << endl;//remove

		if (freq[i] > highestFreq) {
			highestFreq2 = highestFreq;
			highestFreqHighestVal2 = highestFreqHighestVal;
			highestFreqLowestVal2 = highestFreqLowestVal;
			highestFreq = freq[i];
			highestFreqHighestVal = readings[i];
			highestFreqLowestVal = readings[i];
		}
		else if (freq[i] == highestFreq) {
			if (readings[i] > highestFreqHighestVal)
				highestFreqHighestVal = readings[i];
			else if (readings[i] < highestFreqLowestVal)
				highestFreqLowestVal = readings[i];
		}
		else if (freq[i] > highestFreq2) {
			highestFreq2 = freq[i];
			highestFreqHighestVal2 = readings[i];
			highestFreqLowestVal2 = readings[i];
		}
		else if (freq[i] == highestFreq2) {
			if (readings[i] > highestFreqHighestVal2)
				highestFreqHighestVal2 = readings[i];
			else if (readings[i] < highestFreqLowestVal2)
				highestFreqLowestVal2 = readings[i];
		}

		//cout << highestFreq << " " << highestFreqHighestVal << " " << highestFreqLowestVal << endl;//remove
		//cout << highestFreq2 << " " << highestFreqHighestVal2 << " " << highestFreqLowestVal2 << endl;//remove
	}

	if (highestFreq2 == 0 || highestFreqHighestVal != highestFreqLowestVal) {
		cout << (abs(highestFreqHighestVal - highestFreqLowestVal)) << endl;
	}
	else {
		long a = abs(highestFreqHighestVal - highestFreqLowestVal2);
		long b = abs(highestFreqHighestVal2 - highestFreqLowestVal);
		cout << ((a>b) ? a : b) << endl;
	}
	//system("pause");
}