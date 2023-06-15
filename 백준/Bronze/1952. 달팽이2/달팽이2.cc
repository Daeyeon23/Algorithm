#include<bits/stdc++.h>
using namespace std;

int diry[4] = {0,1,0,-1};
int dirx[4] = { 1,0,-1,0 };

int Map[100][100];
int M, N;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> N >> M;

	int y = 0;
	int x = 0;
	int ans = 0;
	int dir = 0;

	while (1) {
		Map[y][x] = 1;

		int dy = y + diry[dir];
		int dx = x + dirx[dir];

		if (dy < 0 || dy >= N || dx < 0 || dx >= M || Map[dy][dx] == 1) {
			dir = (dir + 1) % 4;
			
			dy = y + diry[dir];
			dx = x + dirx[dir];
			if (Map[dy][dx] == 1) break;
			ans++;
		}
		y = dy;
		x = dx;

	}

	cout << ans;

	return 0;
}