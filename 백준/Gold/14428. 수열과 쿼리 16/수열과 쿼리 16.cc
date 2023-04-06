#include<bits/stdc++.h>
using namespace std;

int N;
int M;
int arr[100010];
int tree[400040];

void init();

int makeTree(int start, int end, int idx);
int changeTree(int start, int end, int idx, int changeidx);
int FindTree(int start, int end, int left, int right, int idx);

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	makeTree(1, N, 1);

	for (int m = 0; m < M; ++m) {
		int cmd, a, b;
		cin >> cmd >> a >> b;

		if (cmd == 1) {
			arr[a] = b;
			changeTree(1, N, 1, a);
		}
		else if (cmd == 2) {
			cout << FindTree(1, N, a, b, 1) << '\n';
		}

	}

	return 0;
}

void init() {
	cin >> N;
	arr[0] = 1999999999;
	for (int i = 1; i <= N; ++i) {
		cin >> arr[i];
	}
	cin >> M;
}

int makeTree(int start, int end, int idx) {
	if (start == end)
		return tree[idx] = start;

	int mid = (start + end) / 2;
	int leftidx = makeTree(start, mid, idx * 2);
	int rightidx = makeTree(mid + 1, end, idx * 2 + 1);
	if (arr[leftidx] < arr[rightidx]) return tree[idx] = leftidx;
	else if (arr[leftidx] > arr[rightidx]) return tree[idx] = rightidx;
	else return tree[idx] = min(leftidx, rightidx);
}

int changeTree(int start, int end, int idx, int changeidx) {
	if (start > changeidx || changeidx > end) return tree[idx];

	if (start == end)
		return tree[idx];

	int mid = (start + end) / 2;
	int leftidx = changeTree(start, mid, idx * 2, changeidx);
	int rightidx = changeTree(mid + 1, end, idx * 2 + 1, changeidx);
	if (arr[leftidx] < arr[rightidx]) return tree[idx] = leftidx;
	else if (arr[leftidx] > arr[rightidx]) return tree[idx] = rightidx;
	else return tree[idx] = min(leftidx, rightidx);
}

int FindTree(int start, int end, int left, int right, int idx) {
	if (left > end || right < start) return 0;

	if (left <= start && end <= right) return tree[idx];

	int mid = (start + end) / 2;
	int leftidx = FindTree(start, mid, left, right, idx * 2);
	int rightidx = FindTree(mid + 1, end, left, right, idx * 2 + 1);
	if (arr[leftidx] < arr[rightidx]) return leftidx;
	else if (arr[leftidx] > arr[rightidx]) return rightidx;
	else return min(leftidx, rightidx);
}