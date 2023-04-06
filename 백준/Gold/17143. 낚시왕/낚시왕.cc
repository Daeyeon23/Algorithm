#include<bits/stdc++.h>
using namespace std;

int R; // 행
int C; // 열
int M; // 상어 수
int ans; // 정답 (누적 크기)

int diry[5] = { 0,-1,1,0,0 }; // 상,하,우,좌
int dirx[5] = { 0,0,0,1,-1 };

struct shark {
	int speed;
	int dir;
	int size;
};

shark Map[101][101];
shark SaveMap[101][101];


void MoveShark() {
	memset(SaveMap, 0, sizeof(SaveMap));

	for (int i = 1; i <= R; ++i) {
		for (int j = 1; j <= C; ++j) {
			if (Map[i][j].size == 0) continue;

			shark now = Map[i][j];
			if (now.dir == 1 || now.dir == 2) { // 위 아래
				int y = (i + diry[now.dir] * now.speed) % ((R - 1) * 2);
				if (y <= 0) y += ((R - 1) * 2);
				
				if (y <= R) {
					if(SaveMap[y][j].size < now.size)	// 크기 커야만 저장
						SaveMap[y][j] = now;
				}
				else {
					y = 2 * R - y;
					if (now.dir == 1) now.dir = 2;	// 방향 전환
					else if (now.dir == 2) now.dir = 1;
					if (SaveMap[y][j].size < now.size)	// 크기 커야만 저장
						SaveMap[y][j] = now;
				}
			}
			else if (now.dir == 3 || now.dir == 4) {// 좌 우
				int x = (j + dirx[now.dir] * now.speed) % ((C - 1) * 2);
				if (x <= 0) x += ((C - 1) * 2);
				if (x <= C) {
					if (SaveMap[i][x].size < now.size)	// 크기 커야만 저장
						SaveMap[i][x] = now;
				}
				else {
					x = 2 * C - x;
					if (now.dir == 3) now.dir = 4;	// 방향 전환
					else if (now.dir == 4) now.dir = 3;
					if (SaveMap[i][x].size < now.size)	// 크기 커야만 저장
						SaveMap[i][x] = now;
				}
			}
		}
	}
	memcpy(Map, SaveMap, sizeof(SaveMap));
}

void CatchShark(int x) {
	for (int i = 1; i <= R; ++i) {
		if (Map[i][x].size == 0)continue;
		ans += Map[i][x].size;
		Map[i][x] = { 0,0,0 };
		return;
	}
}


void init() {
	cin >> R >> C >> M;
	for (int m = 0; m < M; ++m) {
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		Map[r][c] = { s,d,z };
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	init();

	for (int j = 1; j <= C; ++j) {
		CatchShark(j);
		MoveShark();
	}
	cout << ans;

	return 0;
}