#include<iostream>
#include<algorithm>
using namespace std;

int N, M;
int path[10];

void dfs(int level, int start) {
	if (level == M) {
		for (int i = 0;i < level;i++) {
			cout << path[i] << ' ';
		}cout << '\n';
		return;
	}

	for (int i = start;i <= N;++i) {
		path[level] = i;
		dfs(level + 1, i + 1);
		path[level] = 0;
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);


	cin >> N >> M;

	dfs(0, 1);


	return 0;
}