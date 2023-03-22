#include<iostream>
#include<algorithm>
using namespace std;

#define MAXN 1000000007

int N, M, K;
long long arr[1000010];
long long tree[4000040];

void init() {
	cin >> N >> M >> K;
	for (int i = 1;i <= N;++i) {
		cin >> arr[i];
	}
}

long long MakeTree(int start, int end, int idx) {
	if (start == end) {
		return tree[idx] = arr[start];
	}

	int mid = (start + end) / 2;
	return tree[idx] = (MakeTree(start, mid, idx * 2) * MakeTree(mid + 1, end, idx * 2 + 1)) % MAXN;
}

long long MulTree(int start, int end, int left, int right, int idx) {
	if (end < left || start > right) return 1;

	if (left <= start && end <= right) return tree[idx];

	int mid = (start + end) / 2;
	return (MulTree(start, mid, left, right, idx * 2) * MulTree(mid + 1, end, left, right, idx * 2 + 1)) % MAXN;
}

long long ChangeTree(int start, int end, int chidx, int idx, long long change) {
	if (start > chidx || end < chidx) return tree[idx];

	if (start == end) {
		return tree[idx] = change;
	}
	int mid = (start + end) / 2;
	return tree[idx] = (ChangeTree(start, mid, chidx, idx * 2, change) * ChangeTree(mid + 1, end, chidx, idx * 2 + 1, change)) % MAXN;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	init();
	MakeTree(1, N, 1);

	for (int i = 0;i < M + K;++i) {
		int cmd;
		cin >> cmd;
		int b, c;
		cin >> b >> c;

		if (cmd == 1) {
			ChangeTree(1, N, b, 1, c);
			arr[b] = c;
		}
		else if (cmd == 2) {
			cout << MulTree(1, N, b, c, 1) << '\n';
		}
	}

	return 0;
}