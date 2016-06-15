#include <iostream>
#include <string>
using namespace std;


int main()
{
	char vowels[] = { 'a', 'e', 'i', 'o', 'u' };
	string word;
	string newWord;
	getline(cin, word);
	for (int i = 0; i < (int)word.length(); i++) {
		bool vowel = false;
		char closest = 'z';
		int  close = 200;
		for (char &n : vowels) {
			if (n == word[i]) {
				vowel = true;
				break;
			}
			else if (abs(n-word[i]) < close) {
				closest = n;
				close = abs(n - word[i]);
			}
		}
		newWord += word[i];
		if (!vowel) {
			newWord += closest;
			if (word[i] == 'z') {
				newWord += 'z';
				break;
			}
			char next = word[i]+1;
			for (char n : vowels) {
				if (n == next) {
					vowel = true;
					break;
				}
			}
			newWord += ((vowel) ? word[i] + 2:next);
		}
	}
	cout << newWord << endl;
	//system("pause");//remove
}