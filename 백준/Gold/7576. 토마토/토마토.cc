#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;


struct node {
	int y, x;
};

int diry[4] = { -1,1,0,0 };
int dirx[4] = { 0,0,-1,1 };
int Map[1010][1010];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> M >> N;
	

	queue<node> q;

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> Map[i][j];
			if (Map[i][j] == 1) {
				q.push({ i,j });
			}
		}
	}

	int day = 0;

	while (!q.empty()) {
		bool flag = false;
		int len = q.size();

		for (int i = 0;i < len;i++) {
			node now = q.front();
			q.pop();

			for (int dir = 0;dir < 4;dir++) {
				int dy = now.y + diry[dir];
				int dx = now.x + dirx[dir];
				if (dy >= N || dy < 0 || dx >= M || dx < 0)continue;
				if (Map[dy][dx] == 1)continue;
				if (Map[dy][dx] == -1)continue;
				Map[dy][dx] = 1;
				q.push({ dy,dx });
				flag = true;
			}
		}

		if(flag)
			day++;
	}

	bool flag = true;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			if (Map[i][j] == 0) {
				flag = false;
				break;
			}
		}
		if (!flag)break;
	}

	if (flag == 0) {
		cout << -1;
	}
	else {
		cout << day;
	}

	return 0;
}