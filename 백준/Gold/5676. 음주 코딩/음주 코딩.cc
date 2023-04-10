#include<bits/stdc++.h>
using namespace std;

int N;
int K;

int arr[100010];
int tree[400040];

void init();
int CheckPM(int k);
int MakeTree(int start, int end, int idx);
int ChangeTree(int start, int end, int idx, int changeidx, int changeDat);
int MulTree(int start, int end, int left, int right, int idx);


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (cin >> N >> K) {
		init();
		MakeTree(1, N, 1);
		for (int k = 0;k < K;++k) {
			char temp;
			int a, b;
			cin >> temp >> a >> b;

			if (temp == 'C') {
				// a 위치
				// b 변경값
				if (CheckPM(arr[a]) != CheckPM(b)) {
					ChangeTree(1, N, 1, a, CheckPM(b));
				}
				arr[a] = b;
			}
			else if (temp == 'P') {
				int Mul = MulTree(1, N, a, b, 1);
				if (Mul == 1) {
					cout << "+";
				}
				else if (Mul == -1) {
					cout << "-";
				}
				else {
					cout << 0;
				}
			}
		}
		cout << '\n';
	}

	return 0;
}

void init() {
	memset(arr, 0, sizeof(arr));
	memset(tree, 0, sizeof(tree));

	for (int i = 1;i <= N;++i) {
		cin >> arr[i];
	}
}

int CheckPM(int k) {
	if (k > 0) return 1;
	else if (k < 0)return -1;
	else return 0;
}

int MakeTree(int start, int end, int idx) {
	if (start == end) {
		return tree[idx] = CheckPM(arr[start]);
	}

	int mid = (start + end) / 2;
	return tree[idx] = CheckPM(MakeTree(start, mid, idx * 2) * MakeTree(mid + 1, end, idx * 2 + 1));
}

int ChangeTree(int start, int end, int idx, int changeidx, int changeDat) {
	if (start > changeidx || end < changeidx) {
		return tree[idx];
	}

	if (start == end) {
		return tree[idx] = changeDat;
	}

	int mid = (start + end) / 2;
	return tree[idx] = CheckPM(ChangeTree(start, mid, idx * 2, changeidx, changeDat) * ChangeTree(mid + 1, end, idx * 2 + 1, changeidx, changeDat));
}

int MulTree(int start, int end, int left, int right, int idx) {
	if (start > right || end < left) return 1;

	if (left <= start && end <= right) return tree[idx];

	int mid = (start + end) / 2;
	return CheckPM(MulTree(start, mid, left, right, idx * 2) * MulTree(mid + 1, end, left, right, idx * 2 + 1));
}