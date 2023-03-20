#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int N, M;

int parent[1010];
int DAT[1010];

int Find(int now) {
	if (parent[now] == now)
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
	
	cin >> N >> M;

	for (int i = 1;i <= N;i++) {
		parent[i] = i;
	}

	for (int i = 0;i < M;i++) {
		int from, to;
		cin >> from >> to;
		Union(from, to);
	}


	for (int i = 1;i <= N;i++) {
		DAT[Find(i)]++;
	}

	int cnt = 0;

	for (int i = 1;i <= N;i++) {
		if (DAT[i] != 0)cnt++;
	}

	cout << cnt;

	return 0;
}