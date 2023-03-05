#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;

int diry[4] = { -1,1,0,0 };
int dirx[4] = { 0,0,-1,1 };

int N, W, H;
int Map[20][20];
int Mincnt;

struct node {
	int y, x;
	int power;
};

void gravity() {
	for (int j = 0; j < W; j++) {
		int arr[15] = { 0 };
		int idx = 0;
		for (int i = H - 1; i >= 0; i--) {
			if (Map[i][j] != 0) {
				arr[idx++] = Map[i][j];
			}
		}
		idx = 0;
		for (int i = H - 1; i >= 0; i--) {
			Map[i][j] = arr[idx++];
		}
	}
}

void blockbreak(int w) {
	node start;
	bool flag = false;
	for (int i = 0; i < H; i++) {
		if (Map[i][w] == 0)continue;
		start = { i,w,Map[i][w] };
		flag = true;
		break;
	}
	if (!flag)return;

	queue<node> q;
	q.push(start);
	Map[start.y][start.x] = 0;

	while (!q.empty()) {
		node now = q.front();
		q.pop();

		if (now.power > 1) {
			for (int i = 0; i < 4; i++) {
				for (int k = 1; k < now.power; k++) {
					int dy = now.y + diry[i] * k;
					int dx = now.x + dirx[i] * k;
					if (dy >= H || dy < 0 || dx >= W || dx < 0)continue;
					if (Map[dy][dx] == 0)continue;
					q.push({ dy,dx,Map[dy][dx] });
					Map[dy][dx] = 0;
				}
			}
		}
	}
	gravity();
}

void dfs(int level) {
	if (level == N) {
		int nowcnt = 0;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (Map[i][j] != 0)nowcnt++;
			}
		}
		Mincnt = min(Mincnt, nowcnt);
		return;
	}

	for (int i = 0; i < W; i++) {
		// 맵 저장
		int saveMap[20][20] = { 0 };
		for (int m = 0; m < H; m++) {
			for (int n = 0; n < W; n++) {
				saveMap[m][n] = Map[m][n];
			}
		}
		// 구슬 쏘기
		blockbreak(i);
		
		dfs(level + 1);
		// 맵 복구
		for (int m = 0; m < H; m++) {
			for (int n = 0; n < W; n++) {
				Map[m][n] = saveMap[m][n];
			}
		}
	}

}

int main() {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		// reset
		memset(Map, 0, sizeof(Map));
		Mincnt = 21e8;

		// input
		cin >> N >> W >> H;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cin >> Map[i][j];
			}
		}

		// solve
		dfs(0);

		// output
		cout << "#" << tc << ' ' << Mincnt << '\n';
	}



	return 0;
}