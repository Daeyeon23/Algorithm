#include<iostream>
#include<algorithm>
using namespace std;

int arr[100010];
int MaxTree[400040];
int MinTree[400040];
int N, M;

void init() {
	cin >> N >> M;
	for (int i = 1;i <= N;++i) {
		cin >> arr[i];
	}
}

int MakeMaxTree(int start, int end, int idx) {
	if (start == end) {
		return MaxTree[idx] = arr[start];
	}

	int mid = (start + end) / 2;
	return MaxTree[idx] = max(MakeMaxTree(start, mid, idx * 2), MakeMaxTree(mid + 1, end, idx * 2 + 1));
}

int MakeMinTree(int start, int end, int idx) {
	if (start == end) {
		return MinTree[idx] = arr[start];
	}

	int mid = (start + end) / 2;
	return MinTree[idx] = min(MakeMinTree(start, mid, idx * 2), MakeMinTree(mid + 1, end, idx * 2 + 1));
}

int FindMax(int start, int end, int left, int right, int idx) {
	if (end < left || right < start) return 0;

	if (left <= start && end <= right) {
		return MaxTree[idx];
	}

	int mid = (start + end) / 2;
	return max(FindMax(start, mid, left, right, idx * 2), FindMax(mid + 1, end, left, right, idx * 2 + 1));
}

int FindMin(int start, int end, int left, int right, int idx) {
	if (end < left || right < start) return 21e8;

	if (left <= start && end <= right) {
		return MinTree[idx];
	}
	
	int mid = (start + end) / 2;
	return min(FindMin(start, mid, left, right, idx * 2), FindMin(mid + 1, end, left, right, idx * 2 + 1));
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	init();
	MakeMaxTree(1, N, 1);
	MakeMinTree(1, N, 1);

	for (int i = 0;i < M;++i) {
		int a, b;
		cin >> a >> b;
		cout << FindMin(1, N, a, b, 1) << ' ' << FindMax(1, N, a, b, 1) << '\n';
	}

	return 0;
}