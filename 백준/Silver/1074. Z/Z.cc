#include<bits/stdc++.h>
using namespace std;

int n, r, c;
int ans;

void dfs(int y, int x, int size) {
	if (y == r && x == c) {
		cout << ans << '\n';
		return;
	}

	if (r < y + size && r >= y && c < x + size && c >= x) {
		dfs(y, x, size / 2);
		dfs(y, x + size / 2, size / 2);
		dfs(y + size / 2, x, size / 2);
		dfs(y + size / 2, x + size / 2, size / 2);
	}
	else {
		ans += size * size;
	}

}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> r >> c;

	dfs(0, 0, (1 << n));

	return 0;
}