#include<bits/stdc++.h>
using namespace std;

int diry[4] = { -1,1,0,0 };
int dirx[4] = { 0,0,-1,1 };

int N;
int Map[501][501];
int DAT[501][501];
int Ans;

void init();

int dfs(int y, int x) {

	int now = Map[y][x];

	bool flag = false;

	int Max = 0;

	for (int dir = 0; dir < 4; ++dir) {
		int dy = y + diry[dir];
		int dx = x + dirx[dir];
		if (dy < 0 || dx < 0 || dy >= N || dx >= N)continue;
		if (Map[dy][dx] <= now)continue;
		flag = true;

		if (DAT[dy][dx] != 0) {
			Max = max(DAT[dy][dx], Max);
		}
		else {
			int next = dfs(dy, dx);
			Max = max(next, Max);
		}

	}

	if (!flag) {
		DAT[y][x] = 1;
	}
	else {
		DAT[y][x] = Max + 1;
	}
	Ans = max(Ans, DAT[y][x]);
	return DAT[y][x];
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	init();
	
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (DAT[i][j] == 0) {
				dfs(i, j);
			}
		}
	}
	cout << Ans;
	return 0;
}

void init() {
	cin >> N;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> Map[i][j];
		}
	}
}