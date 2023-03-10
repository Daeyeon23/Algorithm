#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int diry[4] = { -1,1,0,0 };
int dirx[4] = { 0,0,-1,1 };

int M, N;
int K;
int Map[60][60];
struct node {
	int y, x;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	for (int tc = 0;tc < T;tc++) {
		cin >> M >> N >> K;

		for (int i = 0;i < K;i++) {
			int a, b;
			cin >> a >> b;
			Map[b][a] = 1;
		}

		int ans = 0;
		for (int i = 0;i < N;i++) {
			for (int j = 0;j < M;j++) {
				if (Map[i][j] == 0)continue;
				node start = { i,j };
				Map[i][j] = 0;
				ans++;
				queue<node> q;
				q.push(start);

				while (!q.empty()) {
					node now = q.front();
					q.pop();

					for (int dir = 0;dir < 4;dir++) {
						int dy = now.y + diry[dir];
						int dx = now.x + dirx[dir];
						if (dy >= N || dy < 0 || dx >= M || dx < 0)continue;
						if (Map[dy][dx] == 0)continue;
						Map[dy][dx] = 0;
						q.push({ dy,dx });
					}
				}
			}
		}
		cout << ans << '\n';
	}
	


	return 0;
}