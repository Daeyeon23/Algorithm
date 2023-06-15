#include<bits/stdc++.h>
using namespace std;

int Map[500][500];

int N, M;
int Ans = 0;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);


	cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> Map[i][j];
		}
	}

	int Sum = 0;

	for (int i = 0; i < N; ++i) {
		Sum = Map[i][0] + Map[i][1] + Map[i][2];

		for (int j = 2; j < M; ++j) {
			if (j != 2) {
				Sum -= Map[i][j - 3];
				Sum += Map[i][j];
			}

			int nowmax = 0;

			if(j+1 < M)
				nowmax = Map[i][j + 1];
			if(i + 1 < N)
				nowmax = max({ nowmax, Map[i + 1][j - 2], Map[i + 1][j - 1], Map[i + 1][j] });
			if (i - 1 >= 0) {
				nowmax = max({ nowmax, Map[i - 1][j - 2], Map[i - 1][j - 1], Map[i - 1][j] });
			}

			Ans = max(Ans, Sum + nowmax);
		}
	}

	for (int j = 0; j < M; ++j) {
		Sum = Map[0][j] + Map[1][j] + Map[2][j];

		for (int i = 2; i < N; ++i) {
			if (i != 2) {
				Sum -= Map[i-3][j];
				Sum += Map[i][j];
			}

			int nowmax = 0;

			if (i + 1 < N)
				nowmax = Map[i+1][j];
			if (j + 1 < M)
				nowmax = max({ nowmax, Map[i - 2][j + 1], Map[i - 1][j + 1], Map[i][j + 1] });
			if (j - 1 >= 0) {
				nowmax = max({ nowmax, Map[i - 2][j - 1], Map[i - 1][j - 1], Map[i][j - 1] });
			}

			Ans = max(Ans, Sum + nowmax);
		}
	}

	for (int i = 0; i < N-1; ++i) {
		Sum = Map[i][0] + Map[i][1];

		for (int j = 1; j < M; ++j) {
			if (j != 1) {
				Sum -= Map[i][j - 2];
				Sum += Map[i][j];
			}

			int nowmax = 0;

			if (j - 2 >= 0) {
				nowmax = max(nowmax, Map[i + 1][j - 2] + Map[i + 1][j - 1]);
			}
			nowmax = max(nowmax, Map[i + 1][j - 1] + Map[i + 1][j]);
			if (j + 1 < M) {
				nowmax = max(nowmax, Map[i + 1][j] + Map[i + 1][j + 1]);
			}

			Ans = max(Ans, Sum + nowmax);
		}
	}

	for (int j = 0; j < M - 1; ++j) {
		Sum = Map[0][j] + Map[1][j];

		for (int i = 1; i < N; ++i) {
			if (i != 1) {
				Sum -= Map[i-2][j];
				Sum += Map[i][j];
			}

			int nowmax = 0;

			if (i - 2 >= 0) {
				nowmax = max(nowmax, Map[i - 2][j + 1] + Map[i - 1][j + 1]);
			}
			nowmax = max(nowmax, Map[i - 1][j + 1] + Map[i][j + 1]);
			if (i + 1 < N) {
				nowmax = max(nowmax, Map[i][j + 1] + Map[i + 1][j + 1]);
			}

			Ans = max(Ans, Sum + nowmax);
		}
	}

	cout << Ans;

	return 0;
}