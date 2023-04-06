#include<bits/stdc++.h>
using namespace std;

int N;
int M;
struct node {
	int odd;
	int even;
};
int arr[100010];
node tree[400040];

node MakeTree(int start, int end, int idx) {
	if (start == end) {
		int N = arr[start];
		if (N % 2 == 0)
			return tree[idx] = { 0,1 };
		else
			return tree[idx] = { 1,0 };
	}

	int mid = (start + end) / 2;

	node left = MakeTree(start, mid, idx * 2);
	node right = MakeTree(mid + 1, end, idx * 2 + 1);
	return tree[idx] = { left.odd + right.odd , left.even + right.even };
}

void ChangeTree(int start, int end, int idx, int changeidx, int oddeven) {
	if (start > changeidx || end < changeidx) return;

	if (oddeven == 0) {	// 짝수로 바꼈을 때
		tree[idx].even++;
		tree[idx].odd--;
	}
	else {	// 홀수로 바꼈을 때
		tree[idx].even--;
		tree[idx].odd++;
	}
	if (start == end) return;

	int mid = (start + end) / 2;
	ChangeTree(start, mid, idx * 2, changeidx, oddeven);
	ChangeTree(mid + 1, end, idx * 2 + 1, changeidx, oddeven);
}

node FindTree(int start, int end, int left, int right, int idx) {
	if (start > right || end < left) return { 0,0 };

	if (left <= start && end <= right) return tree[idx];

	int mid = (start + end) / 2;
	node leftnode = FindTree(start, mid, left, right, idx * 2);
	node rightnode = FindTree(mid + 1, end, left, right, idx * 2 + 1);
	return { leftnode.odd + rightnode.odd , leftnode.even + rightnode.even };
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> arr[i];
	cin >> M;
	MakeTree(1, N, 1);

	for (int i = 0; i < M; ++i) {
		int a, b, c;
		cin >> a >> b >> c;

		if (a == 1) {
			if (arr[b] % 2 != c % 2) {
				arr[b] = c;
				ChangeTree(1, N, 1, b, c % 2);
			}
		}
		else if (a == 2) {
			cout << FindTree(1, N, b, c, 1).even << '\n';
		}
		else if (a == 3) {
			cout << FindTree(1, N, b, c, 1).odd << '\n';
		}
	}

	return 0;
}