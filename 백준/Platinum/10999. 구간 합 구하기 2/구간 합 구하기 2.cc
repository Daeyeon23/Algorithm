#include<bits/stdc++.h>
using namespace std;

// typedef long long ll;
using ll = long long;

int N;	// 수의 개수
int M;	// 수 변경이 일어나는 횟수
int K;	// 구간 합 출력 횟수

constexpr int SIZE = 1000010;

ll arr[SIZE];
ll Tree[SIZE * 4];
ll DAT[SIZE * 4];	// 변경 값 저장

void init() {
	memset(arr, 0, sizeof(arr));
	memset(Tree, 0, sizeof(Tree));
	memset(DAT, 0, sizeof(DAT));
	cin >> N >> M >> K;
	for (int i = 1;i <= N; ++i) {
		cin >> arr[i];
	}
}

ll MakeTree(int start, int end, int idx) {
	if (start == end) {
		return Tree[idx] = arr[start];
	}

	int mid = (start + end) / 2;
	return Tree[idx] = MakeTree(start, mid, idx * 2) + MakeTree(mid + 1, end, idx * 2 + 1);
}


void UpdateTree(int start, int end, int left, int right, int idx, ll change) {
	if (start > right || left > end) return;

	int checkStart = max(start, left);
	int checkEnd = min(end, right);

	Tree[idx] += DAT[idx] * (end - start + 1);
	Tree[idx] += change * (checkEnd - checkStart + 1);

	if (start == end) {
		DAT[idx] = 0;
		return;
	}
	DAT[idx * 2] += DAT[idx];
	DAT[idx * 2 + 1] += DAT[idx];

	if (left <= start && end <= right) {	// 전부 포함될때
		DAT[idx * 2] += change;
		DAT[idx * 2 + 1] += change;
		DAT[idx] = 0;
		return;
	}
	int mid = (start + end) / 2;
	UpdateTree(start, mid, left, right, idx * 2, change);
	UpdateTree(mid + 1, end, left, right, idx * 2 + 1, change);
	DAT[idx] = 0;
	return;
}


ll SumTree(int start, int end, int left, int right, int idx) {
	if (start > right || left > end) return 0;

	if (DAT[idx] != 0) {
		Tree[idx] += (end - start + 1) * DAT[idx];
		if (start != end) {
			DAT[idx * 2] += DAT[idx];
			DAT[idx * 2 + 1] += DAT[idx];
		}
		DAT[idx] = 0; 
	}

	if (left <= start && end <= right) {
	
		return Tree[idx];
	}

	int mid = (start + end) / 2;
	return SumTree(start, mid, left, right, idx * 2) + SumTree(mid + 1, end, left, right, idx * 2 + 1);
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	init();
	MakeTree(1, N, 1);

	for (int i{}; i < M + K; ++i) {
		int cmd;
		cin >> cmd;

		if (cmd == 1) { // 값 변경
			int From, To;
			ll Change;
			cin >> From >> To >> Change;
			
			UpdateTree(1, N, From, To, 1, Change);
		}
		else if (cmd == 2) {	// 구간 합 출력
			int From, To;
			cin >> From >> To;
			cout << SumTree(1, N, From, To, 1) << '\n';
		}
	}

	return 0;
}