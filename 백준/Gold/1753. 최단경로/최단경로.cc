#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int V, E;
struct node {
	int to, cost;

	bool operator < (node next) const {
		return cost > next.cost;
	}
};
vector<node> v[20010];

int DAT[20010];



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> V >> E;

	int start;
	cin >> start;

	for (int i = 0;i < E;++i) {
		int from, to, cost;
		cin >> from >> to >> cost;
		v[from].push_back({ to,cost });
	}

	for (int i = 1;i <= V;i++) {
		DAT[i] = 21e8;
	}
	DAT[start] = 0;

	priority_queue<node> pq;

	pq.push({ start,0 });

	while (!pq.empty()) {
		node now = pq.top();
		pq.pop();

		if (DAT[now.to] < now.cost)continue;

		int len = v[now.to].size();
		
		for (int i = 0;i < len;++i) {
			node next = v[now.to][i];

			if (DAT[next.to] > next.cost + now.cost) {
				DAT[next.to] = next.cost + now.cost;
				pq.push({ next.to, DAT[next.to] });
			}
		}
	}

	
	for (int i = 1;i <= V;++i) {
		if (DAT[i] == 21e8) {
			cout << "INF" << '\n';
		}
		else {
			cout << DAT[i] << '\n';
		}
	}

	return 0;
}