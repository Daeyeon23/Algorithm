/*
얼음 위치를 저장하고 매번 4방향을 체크하면 너무 비효율적!
물 위치를 기준으로 4방향을 확인하여 얼음 녹이기.
녹인 자리를 다시 queue에 넣기.

백조의 이동도 queue를 이용해서 이동.
얼음을 만나면 그 위치를 저장하기. (다음 날에 물이 될것)

*/

#include<bits/stdc++.h>
using namespace std;

int diry[4] = { -1,1,0,0 };
int dirx[4] = { 0,0,-1,1 };

int R, C;
char Map[1500][1500];
bool visited[1500][1500]; // 백조 방문 체크
bool Finish = false;

struct node {
	int y, x;
};

queue<node> Water;	// 물 위치 저장
queue<node> Swan;	// 백조 위치 저장

node Swanpos[2];

void init();
void MoveSwan();
void MeltIce();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	init();

	int Day = 0;

	while (1) {
		MoveSwan();
		if (Finish) break;
		MeltIce();
		Day++;
	}

	cout << Day;

	return 0;
}

void init() {
	cin >> R >> C;
	int swancnt = 0;
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			cin >> Map[i][j];
			if (Map[i][j] != 'X') {
				Water.push({ i,j });
			}
			if (Map[i][j] == 'L') {
				Swanpos[swancnt++] = { i,j };
			}
		}
	}
	Swan.push({ Swanpos[0] });
	visited[Swanpos[0].y][Swanpos[0].x] = 1;
}

bool Swanvisit[1500][1500] = { 0 };

void MoveSwan() {

	queue<node> NextSwan;

	while (!Swan.empty()) {
		node now = Swan.front();
		Swan.pop();

		if (now.y == Swanpos[1].y && now.x == Swanpos[1].x) {
			Finish = true;
			return;
		}
		
		for (int dir = 0; dir < 4; dir++) {
			int dy = now.y + diry[dir];
			int dx = now.x + dirx[dir];
			if (dy < 0 || dy >= R || dx < 0 || dx >= C)continue;
			if (Map[dy][dx] == 'X') {
				if (Swanvisit[dy][dx] == 1) continue;
				Swanvisit[dy][dx] = 1;
				NextSwan.push({ dy,dx });
				continue;
			}
			if (visited[dy][dx] == 1) continue;
			visited[dy][dx] = 1;
			Swan.push({ dy,dx });
		}
	}

	Swan = NextSwan;
}

bool icevisit[1500][1500] = { 0 };

void MeltIce() {

	int Size = Water.size();
	

	for (int i = 0; i < Size; ++i) {

		node now = Water.front();
		Water.pop();

		for (int dir = 0; dir < 4; ++dir) {
			int dy = now.y + diry[dir];
			int dx = now.x + dirx[dir];
			if (dy < 0 || dy >= R || dx < 0 || dx >= C)continue;
			if (Map[dy][dx] != 'X') continue;
			if (icevisit[dy][dx] == 1)continue;
			icevisit[dy][dx] = 1;
			Map[dy][dx] = '.';
			Water.push({ dy,dx });
		}
	}


}