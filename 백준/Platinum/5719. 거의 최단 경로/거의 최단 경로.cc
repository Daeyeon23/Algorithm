#include<bits/stdc++.h>
using namespace std;

int N;	// 장소의 수
int M;	// 도로의 수
int S;  // 시작점
int D;  // 도착점

struct node {
	int to;
	int cost;

	bool operator < (node next)const {
		return cost > next.cost;
	}
};

int Link[501][501];
vector<int> path[501];
bool visited[501];

void init();
int Solve();
void EraseMinPath(int idx);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (1) {
		init();
		if (N == 0 && M == 0)return 0;

		int Min = Solve();
		EraseMinPath(D);
		memset(visited, 0, sizeof(visited));

		for (int i = 0; i < 501; ++i) {
			path[i].clear();
		}

		if (Min == 21e8) {
			cout << -1 << '\n';
			continue;
		}

		while (1) {
			int temp = Solve();
			if (temp != Min) {
				if (temp == 21e8) {
					cout << -1 << '\n';
				}
				else
				{
					cout << temp << '\n';
				}
				break;
			}
			EraseMinPath(D);
			for (int i = 0; i < 501; ++i) {
				path[i].clear();
			}
			memset(visited, 0, sizeof(visited));

		}

	}

	return 0;
}

void init() {
	memset(Link, 0, sizeof(Link));
	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < 501; ++i) {
		path[i].clear();
	}
	cin >> N >> M;
	if (N == 0 && M == 0)return;
	cin >> S >> D;
	for (int i = 0; i < M; ++i) {
		int from, to, cost;
		cin >> from >> to >> cost;
		Link[from][to] = cost;
	}
}

int Solve() {
	priority_queue<node> pq;

	int visited[501] = { 0 };
	fill_n(&visited[0], 501, 21e8);

	visited[S] = 0;

	for (int i = 0; i < N; ++i) {
		if (Link[S][i] == 0)continue;
		pq.push({ i,Link[S][i] });
		path[i].push_back(S);
		visited[i] = Link[S][i];
	}


	while (!pq.empty()) {
		node now = pq.top();
		pq.pop();

		if (visited[now.to] < now.cost)continue;

		for (int i = 0; i < N; ++i) {
			if (Link[now.to][i] == 0)continue;
			if (visited[i] < now.cost + Link[now.to][i])continue;
			if (visited[i] == now.cost + Link[now.to][i]) {
				path[i].push_back(now.to);
			}
			else {
				path[i].clear();
				path[i].push_back(now.to);
				visited[i] = now.cost + Link[now.to][i];
				pq.push({ i,visited[i] });
			}
			

		}
	}

	return visited[D];
}

void EraseMinPath(int idx) {
	if (visited[idx] == 1) {
		return;
	}

	visited[idx] = 1;

	for (int i = 0; i < path[idx].size(); ++i) {
		int next = path[idx][i];
		Link[next][idx] = 0;
		if (next == S) continue;

		EraseMinPath(next);
	}
}