#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int V;	// 정점 수
int E;	// 간선 수
struct node {
	int from;
	int to;
	int cost;

	bool operator < (node next)const {
		return cost > next.cost;
	}
};
priority_queue<node> pq;

int parent[10010];

int Find(int now) {
	if (now == parent[now]) {
		return now;
	}

	return parent[now] = Find(parent[now]);
}

void Union(int a, int b) {
	int pa = Find(a);
	int pb = Find(b);

	if (pa == pb)return;

	parent[pb] = pa;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> V >> E;

	for (int i = 0; i < E; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		pq.push({ from,to,cost });
	}

	for (int i = 1; i < V; i++) {
		parent[i] = i;
	}
	int ans = 0;

	while (!pq.empty()) {
		node now = pq.top();
		pq.pop();

		int a = now.from;
		int b = now.to;
		if (Find(a) == Find(b))continue;
		Union(a, b);
		ans += now.cost;
	}
	cout << ans;

	return 0;
}