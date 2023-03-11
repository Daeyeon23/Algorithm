#include<iostream>
#include<algorithm>
using namespace std;

int N;
int color[1010][3];
int DP[1010][3];


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> color[i][j];
		}
	}
	for (int i = 0; i < 3; i++) {
		DP[0][i] = color[0][i];
	}

	for (int i = 1; i < N; i++) {
		DP[i][0] = min(DP[i - 1][1], DP[i - 1][2]) + color[i][0];
		DP[i][1] = min(DP[i - 1][0], DP[i - 1][2]) + color[i][1];
		DP[i][2] = min(DP[i - 1][0], DP[i - 1][1]) + color[i][2];
	}

	cout << min({ DP[N - 1][0],DP[N - 1][1] ,DP[N - 1][2] });

	return 0;
}