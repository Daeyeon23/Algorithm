#include<iostream>
#include<algorithm>
using namespace std;

int parent[110];

int Find(int now) {
	if (now == parent[now])
		return now;
	return parent[now] = Find(parent[now]);
}

void Union(int a, int b) {
	int pa = Find(a);
	int pb = Find(b);

	if (pa == pb)return;

	parent[pb] = pa;
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;

	cin >> N >> M;

	for (int i = 1;i <= N;i++) {
		parent[i] = i;
	}

	for (int i = 0;i < M;i++) {
		int from, to;
		cin >> from >> to;

		Union(from, to);
	}

	int cnt = 0;
	for (int i = 2;i <= N;i++) {
		if (Find(i) == Find(1)) {
			cnt++;
		}
	}
	cout << cnt;

	return 0;
}