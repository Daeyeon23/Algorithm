#include<bits/stdc++.h>
using namespace std;

int K, W, H;
int Map[200][200];
int DAT[200][200][31];

int diry[4] = { -1,1,0,0 };
int dirx[4] = { 0,0,-1,1 };
int hdiry[8] = { -1,-2,-2,-1,1,2,2,1 };
int hdirx[8] = { -2,-1,1,2,2,1,-1,-2 };


struct node {
	int y, x;
	int cost;
	int horse;

	bool operator < (node next)const {
		if (cost > next.cost) return true;
		if (cost < next.cost) return false;
		return horse > next.horse;
	}
};

priority_queue<node> pq;

void init();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	init();

	pq.push({ 0,0,0,0 });
	for (int k = 0; k < 31; ++k) {
		DAT[0][0][k] = 0;
	}

	while (!pq.empty()) {
		node now = pq.top();
		pq.pop();

		if (now.y == H - 1 && now.x == W - 1) {
			cout << now.cost;
			return 0;
		}
		if (DAT[now.y][now.x][now.horse] < now.cost) continue;

		for (int dir = 0; dir < 4; ++dir) {
			int dy = now.y + diry[dir];
			int dx = now.x + dirx[dir];

			if (dy < 0 || dy >= H || dx < 0 || dx >= W)continue;
			if (Map[dy][dx] == 1)continue;
			if (DAT[dy][dx][now.horse] <= now.cost + 1)continue;

			for (int k = now.horse; k <= K; ++k) {
				if (DAT[dy][dx][k] <= now.cost + 1) break;
				DAT[dy][dx][k] = now.cost + 1;
			}
			
			pq.push({ dy,dx,DAT[dy][dx][now.horse],now.horse});

		}

		if (now.horse == K) continue;

		for (int dir = 0; dir < 8; ++dir) {
			int dy = now.y + hdiry[dir];
			int dx = now.x + hdirx[dir];

			if (dy < 0 || dy >= H || dx < 0 || dx >= W)continue;
			if (Map[dy][dx] == 1)continue;
			if (DAT[dy][dx][now.horse+1] <= now.cost + 1)continue;

			for (int k = now.horse+1; k <= K; ++k) {
				if (DAT[dy][dx][k] <= now.cost + 1) break;
				DAT[dy][dx][k] = now.cost + 1;
			}

			pq.push({ dy,dx,DAT[dy][dx][now.horse+1],now.horse+1 });
		}
	}
	cout << -1;

	return 0;
}

void init() {
	cin >> K >> W >> H;
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			cin >> Map[i][j];
		}
	}
	fill_n(&DAT[0][0][0], 200 * 200 * 31, 21e8);
}