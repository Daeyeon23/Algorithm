#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main() {
	int T;
	cin >> T;

	for (int tc = 0; tc < T; tc++) {

		string temp;
		cin >> temp;
		int len = temp.length();

		int score = 0;
		int same = 0;
		for (int i = 0; i < len; i++) {
			if (temp[i] == 'O') {
				same++;
				score += same;
			}
			else {
				same = 0;
			}
		}

		cout << score << '\n';





	}



	return 0;
}