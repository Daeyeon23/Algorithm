#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int DAT[26];

int main() {

	string A;
	cin >> A;

	for (int i = 0; i < 26; i++) {
		DAT[i] = -1;
	}

	for (int i = 0; i < A.length(); i++) {
		int temp = A[i] - 'a';
		if (DAT[temp] == -1) {
			DAT[temp] = i;
		}
	}

	for (int i = 0; i < 26; i++) {
		cout << DAT[i] << ' ';
	}


	return 0;
}