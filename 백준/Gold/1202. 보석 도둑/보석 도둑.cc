#include<bits/stdc++.h>
using namespace std;

int N, K;

int C[300010];
long long ans;
struct node {
	int M;
	int V;

	bool operator < (node next)const {
		return V < next.V;
	}
};

node arr[300010];

bool sortWeight(node left, node right) {
	return left.M < right.M;
}

priority_queue<node> pq;

void init() {
	cin >> N >> K;
	for (int i = 0;i < N;++i) {
		cin >> arr[i].M >> arr[i].V;
	}
	for (int i = 0;i < K;++i) {
		cin >> C[i];
	}
	sort(arr, arr + N, sortWeight);
	sort(C, C + K);
}

void solve() {

	int idx = 0;
	for (int i = 0;i < K;++i) {	// 가방 수 만큼
		int nowWeight = C[i];
		while (arr[idx].M <= nowWeight && idx < N) {
			pq.push(arr[idx++]);
		}
		if (!pq.empty()) {
			ans += pq.top().V;
			pq.pop();
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	init();
	solve();

	cout << ans;


	return 0;
}