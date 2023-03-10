#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int diry[4] = { -1,1,0,0 };
int dirx[4] = { 0,0,-1,1 };

int N;	// 세로
int M;	// 가로
int Map[10][10];
int ans = 21e8;
int blocknum;	// 1 수

struct node {
	int y, x;
};
vector<node> Empty;
vector<node> Virus;

vector<node> path;


int solve() {
	int SolveMap[10][10];

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			SolveMap[i][j] = Map[i][j];
		}
	}

	for (int i = 0;i < 3;i++) {
		SolveMap[path[i].y][path[i].x] = 1;
	}

	int cnt = 0;

	int visited[10][10] = { 0 };
	for (int v = 0;v < Virus.size();v++) {
		queue<node> q;
		q.push(Virus[v]);
		
		visited[Virus[v].y][Virus[v].x] = 1;

		while (!q.empty()) {
			node now = q.front();
			q.pop();

			cnt++;

			for (int dir = 0;dir < 4;dir++) {
				int dy = now.y + diry[dir];
				int dx = now.x + dirx[dir];
				if (dy >= N || dy < 0 || dx >= M || dx < 0)continue;
				if (visited[dy][dx] == 1) continue;
				if (SolveMap[dy][dx] != 0)continue;
				visited[dy][dx] = 1;
				q.push({ dy,dx });
			}
		}
	}
	return cnt;

}



void dfs(int level, int start) {
	if (level == 3) {
		ans = min(ans,solve());
		return;
	}

	for (int i = start;i < Empty.size();i++) {
		path.push_back({ Empty[i] });
		dfs(level + 1, i + 1);
		path.pop_back();
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N >> M;
	

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> Map[i][j];
			if (Map[i][j] == 2) {
				Virus.push_back({ i,j });
			}
			else if (Map[i][j] == 0) {
				Empty.push_back({ i,j });
			}
			else {
				blocknum++;
			}
		}
	}

	dfs(0, 0);
	cout << N*M - ans - blocknum - 3;
	return 0;
}