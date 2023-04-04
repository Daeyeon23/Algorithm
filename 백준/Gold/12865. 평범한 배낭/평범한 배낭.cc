#include<bits/stdc++.h>
using namespace std;

int N;	// 물품 수
int K;	// 버틸 수 있는 무게
int arr[101][2];	// 무게, 가치 정보
int DP[101][100010];

void init() {
	cin >> N >> K;
	for (int i = 1; i <= N; ++i) {
		cin >> arr[i][0] >> arr[i][1];
	}
}

int solve() {

	for (int i = 1; i <= N; ++i) {
		for (int k = 1; k <= K; ++k) {
			if (k < arr[i][0]) {	// 이번 물건을 못 넣을때.
				DP[i][k] = DP[i - 1][k];
			}
			else {
				DP[i][k] = max(DP[i - 1][k - arr[i][0]] + arr[i][1], DP[i - 1][k]);
			}
		}
	}

	return DP[N][K];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	init();
	cout << solve() << '\n';

	return 0;
}