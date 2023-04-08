#include<bits/stdc++.h>
using namespace std;

int N;
int M;

int Map[1010][1010];
int diry[4] = { -1,1,0,0 };
int dirx[4] = { 0,0,-1,1 };

struct node {
	int y, x;
	int cost;
	bool broken;

	bool operator < (node next)const {
		return cost > next.cost;
	}
};

priority_queue<node> pq;


int DAT[1010][1010][2];

void init() {
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		string temp;
		cin >> temp;
		for (int j = 0; j < M; ++j) {
			Map[i][j] = temp[j]-'0';
		}
	}
	fill_n(&DAT[0][0][0], 1010 * 1010 * 2, 99999999);
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	init();

	pq.push({ 0,0,1,0 });
	DAT[0][0][0] = 1;

	while (!pq.empty()) {
		node now = pq.top();
		pq.pop();

		if (now.cost > DAT[now.y][now.x][now.broken]) continue;

		for (int dir = 0; dir < 4; dir++) {
			int dy = now.y + diry[dir];
			int dx = now.x + dirx[dir];
			if (dy < 0 || dy >= N || dx < 0 || dx >= M)continue;		
			if (DAT[dy][dx][now.broken] <= now.cost + 1) continue;

			if (now.broken == 0) {
				if (Map[dy][dx] == 1) {
					DAT[dy][dx][1] = now.cost + 1;
					pq.push({ dy,dx,DAT[dy][dx][1],true});
				}
				else {
					DAT[dy][dx][0] = now.cost + 1;
					pq.push({ dy,dx,DAT[dy][dx][0],false});
				}
			}
			else {
				if (Map[dy][dx] == 1)continue;
				DAT[dy][dx][1] = now.cost + 1;
				pq.push({ dy,dx,DAT[dy][dx][1],true});
			}
		}

	}

	if (DAT[N - 1][M - 1][0] == 99999999 && DAT[N - 1][M - 1][1] == 99999999) {
		cout << -1;
	}
	else {
		cout << min(DAT[N - 1][M - 1][0], DAT[N - 1][M - 1][1]);
	}

	return 0;
}