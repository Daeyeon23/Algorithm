#include<iostream>
#include<algorithm>
using namespace std;

int N, K;
struct node {
	int weight;
	int cost;
};
node arr[111];
int DP[101][100010];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	
	cin >> N >> K;

	for (int i = 1; i <= N; ++i) {
		int w, c;
		cin >> w >> c;
		arr[i].weight = w;
		arr[i].cost = c;
	}

	for (int i = 1; i <= K; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (arr[j].weight > i) {
				DP[j][i] = DP[j - 1][i];
			}
			else {
				DP[j][i] = max(DP[j - 1][i - arr[j].weight] + arr[j].cost, DP[j - 1][i]);
			}
		}
	}

	cout << DP[N][K];
	return 0;
}