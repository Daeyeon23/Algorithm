#include<bits/stdc++.h>
using namespace std;

int N, M;
int arr[100001];
int tree[400004];

void init();
int MakeTree(int left, int right, int idx);
int FindTree(int left, int right, int start, int end, int idx);

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	MakeTree(1, N, 1);

	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		cout << FindTree(1, N, a, b, 1) << '\n';
	}

	return 0;
}

void init() {
	cin >> N >> M;
	for (int i = 1; i <= N; ++i) {
		cin >> arr[i];
	}
}

int MakeTree(int left, int right, int idx) {
	if (left == right) return tree[idx] = arr[left];

	int mid = (left + right) / 2;
	return tree[idx] = min(MakeTree(left, mid, idx * 2), MakeTree(mid + 1, right, idx * 2 + 1));
}

int FindTree(int left, int right, int start, int end, int idx) {
	if (right < start || end < left) return 21e8;

	if (start <= left && right <= end) {
		return tree[idx];
	}

	if (left == right) return tree[idx];

	int mid = (left + right) / 2;
	return min(FindTree(left, mid, start, end, idx * 2), FindTree(mid + 1, right, start, end, idx * 2 + 1));
}

