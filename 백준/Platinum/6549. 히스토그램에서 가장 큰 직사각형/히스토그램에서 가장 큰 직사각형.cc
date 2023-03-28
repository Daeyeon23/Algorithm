#include<bits/stdc++.h>
using namespace std;

int N;
long long arr[100010];
int tree[400040];
long long ans;



int InitTree(int start, int end, int idx) {
	if (start == end) {
		return tree[idx] = start;
	}

	int mid = (start + end) / 2;
	int left = InitTree(start, mid, idx * 2);
	int right = InitTree(mid + 1, end, idx * 2 + 1);
	if (arr[left] <= arr[right]) {
		return tree[idx] = left;
	}
	else {
		return tree[idx] = right;
	}
}

int FindMin(int start, int end, int left, int right, int idx) {
	if (start > right || end < left) {
		return -1;
	}
	if (left <= start && end <= right) {
		return tree[idx];
	}
	int mid = (start + end) / 2;
	int Left = FindMin(start, mid, left, right, idx * 2);
	int Right = FindMin(mid + 1, end, left, right, idx * 2 + 1);

	if (Left == -1) return Right;
	if (Right == -1)return Left;

	if (arr[Left] <= arr[Right]) {
		return Left;
	}
	else {
		return Right;
	}
}

void Solve(int start, int end) {
	int Min = FindMin(1, N, start, end, 1);
	long long sum = arr[Min] * (end - start + 1);
	ans = max(ans, sum);

	if (start == end) return;

	if (Min != start) {
		Solve(start, Min - 1);
	}
	if (Min != end) {
		Solve(Min + 1, end);
	}

}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (1) {
		cin >> N;
		if (N == 0) break;

		memset(arr, 0, sizeof(arr));
		memset(tree, 0, sizeof(tree));
		ans = 0;

		for (int i = 1;i <= N;++i) {
			cin >> arr[i];
		}
		InitTree(1, N, 1);
		Solve(1, N);
		cout << ans << '\n';
	}
	return 0;
}