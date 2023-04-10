/*
섬의 개수 : 최대 6개 -> 얼마 안되는구나!
맵 크기 : 10x10

MxN 돌면서 bfs 이용해서 섬 위치 정보를 vector에 저장하자.
이 과정에서 Visited에 섬 번호를 표기해주자.

Union-Find 이용하면 중복하지 않고 연결할 수 있지 않을까?

vector 에 저장된 위치에서 4방향 확인해서 0이 아니면 같은 섬이므로 탐색 x
진행하다가 다른 0이 아닌 값 찾으면 정보 PQ에 저장하기. 다리 길이는 최소 2이다!
(출발지, 도착지, 다리길이) -> 다리길이 짧은순

모든 섬 탐색 했으면 pq에 저장된 값 순서대로 Union-Find 이용해서 연결하자!

*/


#include<bits/stdc++.h>
using namespace std;

struct node {
	int y, x;
};

struct Link {
	int start;
	int end;
	int cost;

	bool operator < (Link next) const {
		return cost > next.cost;
	}
};

int N, M;
int Map[11][11];
int visited[11][11];

int parent[10];

int diry[4] = { -1,1,0,0 };
int dirx[4] = { 0,0,-1,1 };
int IslandNum = 1;
int ans = 0;

vector<node> IslandPos[7];
priority_queue<Link> pq;

void init();
int Find(int now);
void Union(int a, int b);
void FindIsland();
void FindNextIsland(int num);
void Solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	init();

	FindIsland();

	for(int i=1;i<IslandNum;++i)
		FindNextIsland(i);

	Solve();

	int Check = Find(1);

	for (int i = 2;i < IslandNum;++i) {
		if (Check != Find(i)) {
			cout << -1;
			return 0;
		}	
	}
	cout << ans;

	return 0;
}

void init() {
	cin >> N >> M;
	for (int i = 0;i < N;++i) {
		for (int j = 0;j < M;++j) {
			cin >> Map[i][j];
		}
	}
	for (int i = 1;i < 10;++i) {
		parent[i] = i;
	}
}

int Find(int now) {
	if (now == parent[now]) {
		return now;
	}

	return parent[now] = Find(parent[now]);
}

void Union(int a, int b) {
	int pa = Find(a);
	int pb = Find(b);

	if (pa == pb) return;

	parent[pb] = pa;
}

void FindIsland() {

	for (int i = 0;i < N;++i) {
		for (int j = 0;j < M;++j) {
			if (Map[i][j] == 0)continue;
			if (visited[i][j] != 0)continue;

			queue<node> q;
			q.push({ i,j });
			visited[i][j] = IslandNum;
			IslandPos[IslandNum].push_back({ i,j });

			while (!q.empty()) {
				node now = q.front();
				q.pop();

				for (int dir = 0;dir < 4;dir++) {
					int dy = now.y + diry[dir];
					int dx = now.x + dirx[dir];

					if (dy < 0 || dy >= N || dx < 0 || dx >= M) continue;
					if (Map[dy][dx] == 0)continue;
					if (visited[dy][dx] != 0)continue;
					visited[dy][dx] = IslandNum;
					IslandPos[IslandNum].push_back({ dy,dx });
					q.push({ dy,dx });
				}
			}
			
			IslandNum++;
		}
	}
}

void FindNextIsland(int num) {
	int len = IslandPos[num].size();
	if (len == 0)return;

	for (int i = 0;i < len; i++) {
		node now = IslandPos[num][i];

		for (int dir = 0;dir < 4;dir++) {
			int dy = now.y + diry[dir];
			int dx = now.x + dirx[dir];
			if (dy < 0 || dy >= N || dx < 0 || dx >= M) continue;
			if (visited[dy][dx] == num)continue;	// 같은 섬 만날경우

			int Bridge = 1; // 다리 길이

			while (1) {
				dy += diry[dir];
				dx += dirx[dir];
				if (dy < 0 || dy >= N || dx < 0 || dx >= M) break;
				if (visited[dy][dx] != 0) {
					if (Bridge == 1) break; // 다리길이 1일때
					pq.push({ num,visited[dy][dx],Bridge });
					break;
				}
				Bridge++;
			}
		}
	}
}

void Solve() {

	while (!pq.empty()) {
		Link now = pq.top();
		pq.pop();

		if (Find(now.start) == Find(now.end)) continue;

		Union(now.start, now.end);
		ans += now.cost;
	}
}
