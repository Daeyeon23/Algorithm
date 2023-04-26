#include<bits/stdc++.h>
using namespace std;

int N;
int ans = 21e8;
vector<int> path;
vector<int> AnsPath;

void dfs(int now, int cnt) {
	if (cnt >= ans) return;
	
	if (now == 1) {
		ans = cnt;
		AnsPath = path;
		return;
	}

	if (now % 3 == 0) {
		path.push_back(now / 3);
		dfs(now / 3, cnt + 1);
		path.pop_back();
	}

	if (cnt >= ans) return;

	if (now % 2 == 0)
	{
		path.push_back(now / 2);
		dfs(now / 2, cnt + 1);
		path.pop_back();
	}

	if (cnt >= ans) return;

	path.push_back(now -1);
	dfs(now-1, cnt + 1);
	path.pop_back();

}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	path.push_back(N);
	dfs(N, 0);

	cout << ans << '\n';
	for (int i = 0;i <= ans;++i) {
		cout << AnsPath[i] << ' ';
	}
	return 0;
}
