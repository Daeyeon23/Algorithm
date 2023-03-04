#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int N, M, P;

struct node {
	int to;
	int cost;

	bool operator < (node next)const {
		return cost > next.cost;
	}
};

vector<node> Map[1001];

int dijkstra(int start, int destination) {
	priority_queue<node> pq;
	pq.push({ start,0 });

	int DAT[1001] = { 0 };
	for (int i = 1;i <= N;i++) {
		DAT[i] = 21e8;
	}
	DAT[start] = 0;

	while (!pq.empty()) {
		node now = pq.top();
		pq.pop();

		if (DAT[now.to] > now.cost) continue;

		for (int i = 0;i < Map[now.to].size();i++) {
			node next = Map[now.to][i];
			int ncost = DAT[now.to] + next.cost;
			if (ncost >= DAT[next.to]) continue;
			DAT[next.to] = ncost;
			pq.push({ next.to, ncost });
		}
	}
	return DAT[destination];
}


int main() {
	cin >> N >> M >> P;

	for (int i = 0;i < M;i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		Map[from].push_back({ to,cost });
	}
	
	int Max = 0;

	for (int i = 1;i <= N;i++) {
		int Sum = 0;
		Sum += dijkstra(i, P);
		Sum += dijkstra(P, i);
		if (Max < Sum)
			Max = Sum;

	}
	cout << Max;

	return 0;
}