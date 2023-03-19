#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

int N, M;
int Map[60][60];
int diry[4] = { -1,1,0,0 };
int dirx[4] = { 0,0,-1,1 };
int EmptyRoom;
int ans = 21e8;

struct node {
	int y, x;
};
vector<node> v;	// 바이러스 위치 저장
int v_size;	// 바이러스 수
vector<int> Select;	// 바이러스 선택

void init() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> Map[i][j];
			if (Map[i][j] == 2) {
				v.push_back({ i,j });
			}
			if (Map[i][j] != 0) {
				Map[i][j] = (-1) * Map[i][j];
			}
			else {
				EmptyRoom++;	// 빈 공간 수
			}
		}
	}
	v_size = v.size();
}


int solve() {
	int CopyMap[60][60];
	memcpy(CopyMap, Map, sizeof(Map));

	queue<node> q;
	
	int len = Select.size();

	for (int i = 0; i < len; i++) {
		q.push(v[Select[i]]);
	}

	int day = 0;
	int cnt = 0;	// 바이러스 변이 수

	while (!q.empty()) {
		int day_len = q.size();
		day++;

		for (int i = 0; i < day_len; i++) {
			node now = q.front();
			q.pop();

			for (int dir = 0; dir < 4; dir++) {
				int dy = now.y + diry[dir];
				int dx = now.x + dirx[dir];
				if (dy >= N || dy < 0 || dx >= N || dx < 0)continue;
				if (CopyMap[dy][dx] == -1)continue;
				if (CopyMap[dy][dx] > 0)continue;
				q.push({ dy,dx });
				if (CopyMap[dy][dx] == -2) {
					CopyMap[dy][dx] = 1;
				}
				if (CopyMap[dy][dx] == 0) {
					CopyMap[dy][dx] = day;
					cnt++;
				}
				if (cnt == EmptyRoom) {
					return day;
				}
			}		
		}	
	}
	return 21e8;

}





void dfs(int level, int start) {	// 바이러스 선택
	if (level == M) {
		ans = min(ans, solve());
		return;
	}
	
	for (int i = start; i < v_size; i++) {
		Select.push_back(i);
		dfs(level + 1, i + 1);
		Select.pop_back();
	}
}


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	if (EmptyRoom == 0) {
		ans = 0;
	}
	else {
		dfs(0, 0);
	}


	if (ans == 21e8)cout << -1;
	else
	{
		cout << ans;
	}
	


	return 0;

}