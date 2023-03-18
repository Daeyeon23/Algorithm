#include<iostream>
#include<algorithm>
using namespace std;

int DP[5010];
int N;

int solve(int now) {

	if (now == 3 || now == 5) {
		return DP[now] = 1;
	}
	if (now == 1 || now == 2 || now == 4)
		return DP[now] = 21e8;

	if (DP[now] != 0)return DP[now];

	return DP[now] = min(solve(now - 3), solve(now - 5)) + 1;
}


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	int ans = solve(N);
	if (ans == 21e8 || ans == 21e8+1)cout << -1;
	else
	{
		cout << ans;
	}




	return 0;
}