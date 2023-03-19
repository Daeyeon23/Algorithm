#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int N, M;
vector<int> v[32111];
int DAT[32111];
int visited[32111];

void init() {
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int from, to;
		cin >> from >> to;
		v[from].push_back(to);
		DAT[to]++;
	}
}

void solve() {

	queue<int> q;
	int cnt = 0;

	for (int i = 1; i <= N; i++) {
		if (DAT[i] == 0) {
			q.push(i);
			visited[i] = 1;
		}
	}

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		cout << now << ' ';
		cnt++;

		int len = v[now].size();
		for (int i = 0; i < len; i++) {
			DAT[v[now][i]]--;
			if (DAT[v[now][i]] == 0 && visited[v[now][i]] == 0) {
				q.push(v[now][i]);
				visited[v[now][i]] = 1;
			}
		}
	}



}


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	init();

	solve();

	return 0;
}