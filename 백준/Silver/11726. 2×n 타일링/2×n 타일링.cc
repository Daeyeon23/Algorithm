#include<iostream>
#include<algorithm>
using namespace std;

int DP[1010];

int solve(int now) {
	if (now == 1) {
		return DP[now] = 1;
	}
	if (now == 0) {
		return DP[now] = 1;
	}
	if (DP[now] != 0) {
		return DP[now];
	}

	return DP[now] = (solve(now-1) + solve(now-2))%10007;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	cout << solve(N);

	return 0;
}