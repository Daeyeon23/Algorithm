#include<iostream>
#include<algorithm>
using namespace std;

int N, M;
int Map[1010][1010];
int DAT[1010][1010];
int X1, Y1, X2, Y2;
int wall;

void init() {
	cin >> N >> M;

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> Map[i][j];
		}
	}
	cin >> Y1 >> X1 >> Y2 >> X2;

	if (Y1 > Y2) {
		int temp = Y1;
		Y1 = Y2;
		Y2 = temp;
	}
	if (X1 > X2) {
		int temp = X1;
		X1 = X2;
		X2 = temp;
	}
	if (Y1 == Y2) {	// 벽이 가로
		wall = 1;
	}
	else if (X1 == X2)	// 벽이 세로
	{
		wall = 2;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	init();

	DAT[0][0] = Map[0][0];

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			if (i == 0 && j == 0)continue;

			int a=-21e8, b=-21e8;

			if (i >= 1) {
				a = DAT[i - 1][j];
			}

			if (j >= 1) {
				b = DAT[i][j - 1];
			}

			if (wall == 1 && i == Y1 && j >= X1 && j < X2) {
				a = -21e8;
			}
			
			if (wall == 2 && j == X1 && i >= Y1 && i < Y2) {
				b = -21e8;
			}
			if (a == -21e8 && b == -21e8) {
				DAT[i][j] = -21e8;
			}
			else {
				DAT[i][j] = max(a, b) + Map[i][j];
			}
		}
	}

	if (DAT[N - 1][M - 1] == -21e8) {
		cout << "Entity";
	}
	else {
		cout << DAT[N - 1][M - 1];
	}


	return 0;
}