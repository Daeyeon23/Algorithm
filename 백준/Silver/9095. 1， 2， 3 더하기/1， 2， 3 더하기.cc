#include<iostream>
#include<algorithm>
using namespace std;

/*
1	1
2	2
3	4
*/
int DAT[15];

int solve(int n) {
	if (DAT[n] != 0) {
		return DAT[n];
	}
	
	return solve(n - 1) + solve(n - 2) + solve(n - 3);
}


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;

	DAT[1] = 1;
	DAT[2] = 2;
	DAT[3] = 4;


	for (int tc = 0; tc < T; tc++) {
		int n;
		cin >> n;

		cout << solve(n) << '\n';
	}

	return 0;
}