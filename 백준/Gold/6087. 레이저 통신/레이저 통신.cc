/*
방향을 바꿀때마다 cost + 1
맵에 cost 최저값을 저장하면서 맵을 채우기.

*/

#include<bits/stdc++.h>
using namespace std;

int diry[4] = { -1,1,0,0 };
int dirx[4] = { 0,0,-1,1 };

int W, H;
int Map[101][101];
int Visited[101][101];
int DirVisited[101][101][4];

struct node {
	int y, x;
	int cost;
	int dir;

	bool operator < (node next) const {
		return cost > next.cost;
	}
};

vector<node> Point;

void init();
void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	init();
	solve();

	cout << Visited[Point[1].y][Point[1].x];

	return 0;
}

void init() {
	cin >> W >> H;
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			char temp;
			cin >> temp;
			if (temp == '*') {
				Map[i][j] = 1;
			}
			else if (temp == 'C') {
				Point.push_back({ i,j });
			}
			Visited[i][j] = 21e8;
		}
	}
}

void solve() {
	priority_queue<node> pq;
	node st = Point[0];
	for (int dir = 0; dir < 4; dir++) {
		st.dir = dir;
		pq.push({ st });
	}
	Visited[st.y][st.x] = 0;

	while (!pq.empty()) {
		node now = pq.top();
		pq.pop();

		if (now.cost > Visited[now.y][now.x])continue;

		for (int dir = 0; dir < 4; dir++) {
			int dy = now.y + diry[dir];
			int dx = now.x + dirx[dir];

			if (dy < 0 || dy >= H || dx < 0 || dx >= W)continue;
			if (Map[dy][dx] == 1) continue;

			int nextcost = now.cost;
			if (dir != now.dir) nextcost++;

			if (Visited[dy][dx] < nextcost) continue; // 방향 다르게 온게 저장이 안되네...
			else if (Visited[dy][dx] == nextcost) {
				if (DirVisited[dy][dx][dir] == 1)continue;
				DirVisited[dy][dx][dir] = 1;
			}
			else {
				for (int k = 0; k < 4; k++) {
					DirVisited[dy][dx][k] = 0;
				}
			}
			
			

			Visited[dy][dx] = nextcost;
			pq.push({ dy,dx,nextcost,dir });

		}

	}
}