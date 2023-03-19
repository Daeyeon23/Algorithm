#include<iostream>
#include<algorithm>
using namespace std;

int N;
int Map[500][500];
int DP[500][500];

int solve(int y, int x) {
	int temp;
	if (x == 0) {
		temp = DP[y - 1][0];
	}
	else if (x == y) {
		temp = DP[y - 1][x - 1];
	}
	else {
		temp = max(DP[y - 1][x - 1], DP[y - 1][x]);
	}
	return temp + Map[y][x];
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> Map[i][j];
		}
	}

	DP[0][0] = Map[0][0];

	for (int i = 1; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			DP[i][j] = solve(i, j);
		}
	}

	int ans = 0;
	for (int j = 0; j < N; j++) {
		ans = max(ans, DP[N - 1][j]);
	}
	cout << ans;

	return 0;
}