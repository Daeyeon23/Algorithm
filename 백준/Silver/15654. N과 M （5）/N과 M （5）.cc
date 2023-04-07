#include<bits/stdc++.h>
using namespace std;

int N;
int M;

int arr[10];
int path[10];
bool visited[10];

void dfs(int level) {
	if (level == M) {
		for (int i = 0;i < M;++i) {
			cout << path[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 0;i < N;++i) {
		if (visited[i] == 1)continue;
		visited[i] = 1;
		path[level] = arr[i];

		dfs(level + 1);
		visited[i] = 0;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0;i < N;++i) {
		cin >> arr[i];
	}

	sort(arr, arr + N);

	dfs(0);

	return 0;
}