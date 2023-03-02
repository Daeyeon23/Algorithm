#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<string>
using namespace std;



int main() {

	int DAT[26] = { 0 };

	string A;
	cin >> A;

	for (int i = 0;i < A.length();i++) {
		if (A[i] >= 'a' && A[i] <= 'z') {
			DAT[A[i] - 'a']++;
		}
		else {
			DAT[A[i] - 'A']++;
		}
	}

	int Max = 0;
	int idx = 0;
	bool flag = true;
	for (int i = 0;i < 26;i++) {
		if (Max < DAT[i])
		{
			Max = DAT[i];
			idx = i;
			flag = true;
		}
		else if (Max == DAT[i]) {
			flag = false;
		}
	}
	if (!flag) {
		cout << "?";
	}
	else {
		cout << char('A' + idx);
	}


	return 0;
}