/*
	다이스트라 문제!
*/
#include<bits/stdc++.h>
using namespace std;

int diry[4] = { -1,1,0,0 };
int dirx[4] = { 0,0,-1,1 };

int N;	// 행
int M;	// 열
int Map[1010][1010];	// 맵
int DAT[1010][1010];	// 최소비용 저장

struct node {
	int y;
	int x;
	int cost;

	bool operator < (node next) const{
		return cost > next.cost;
	}
};

priority_queue<node> pq;

void init();
void solve();


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	
	solve();

	int ans = DAT[N - 1][M - 1];

	if (ans == 21e8 || Map[0][0] == -1) {
		cout << -1;
	}
	else {
		cout << ans;
	}

	return 0;
}

void init() {
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> Map[i][j];
			DAT[i][j] = 21e8;
		}
	}
}

void solve() {
	pq.push({ 0,0,Map[0][0] });
	DAT[0][0] = Map[0][0];

	while (!pq.empty()) {
		node now = pq.top();
		pq.pop();

		if (now.cost > DAT[now.y][now.x]) continue;

		for (int dir = 0; dir < 4; ++dir) {
			int dy = now.y + diry[dir];
			int dx = now.x + dirx[dir];
			if (dy < 0 || dy >= N || dx < 0 || dx >= M)continue;	// 경계면
			if (Map[dy][dx] == -1)continue;	// 벽
			if (now.cost + Map[dy][dx] >= DAT[dy][dx]) continue;	// 이미 비용이 더 적으면 리턴
			DAT[dy][dx] = now.cost + Map[dy][dx];
			pq.push({ dy, dx, DAT[dy][dx] });
		}
	}

}