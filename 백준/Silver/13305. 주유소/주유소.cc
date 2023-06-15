#include<bits/stdc++.h>
using namespace std;

int dist[100000];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	for (int i = 0; i < N-1; ++i) {
		cin >> dist[i];
	}

	int Min = 21e8;
	long long ans = 0;
	for (int i = 0; i < N; ++i) {
		int cost;
		cin >> cost;
		if (i == N - 1) {
			cout << ans;
			return 0;
		}

		Min = min(Min, cost);

		ans += Min * dist[i];
	}



	return 0;
}
