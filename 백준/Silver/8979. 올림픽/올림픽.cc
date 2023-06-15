#include<bits/stdc++.h>
using namespace std;

int N, K;

struct node {
	int num;
	int gold;
	int silver;
	int bronze;

	bool operator < (node next)const {
		if (gold > next.gold) return true;
		if (gold < next.gold) return false;
		if (silver > next.silver) return true;
		if (silver < next.silver) return false;
		return bronze > next.bronze;
	}
};

priority_queue<node> pq;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> K;

	for (int i = 0; i < N; ++i) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		pq.push({ a,b,c,d });
	}

	int ans = 1;
	int same = 0;
	node before = pq.top();
	pq.pop();

	while (!pq.empty()) {
		node now = pq.top();
		pq.pop();

		if (before.gold == now.gold && before.silver == now.silver && before.bronze == now.bronze) {
			same++;
		}
		else {
			ans = ans + same + 1;
			same = 0;
			before = now;
		}

		if (now.num == K) {
			cout << ans;
			return 0;
		}
	}

	return 0;
}