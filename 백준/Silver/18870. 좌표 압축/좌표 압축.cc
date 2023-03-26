#include<bits/stdc++.h>
using namespace std;

int N;
struct node {
	int idx;
	int dat;
	int ans;

	bool operator < (node next) const {
		return dat < next.dat;
	}
};

bool cmd(node left, node right) {
	return left.idx < right.idx;
}

node arr[1000010];

void init() {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i].dat;
		arr[i].idx = i;
	}
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	sort(arr, arr + N);

	int now = arr[0].dat;
	int nowcnt = 0;
	for (int i = 0; i < N; ++i) {
		if (now < arr[i].dat) {
			now = arr[i].dat;
			nowcnt++;
			arr[i].ans = nowcnt;
			
		}
		else {
			arr[i].ans = nowcnt;
		}
	}

	sort(arr, arr + N, cmd);

	for (int i = 0; i < N; ++i) {
		cout << arr[i].ans << ' ';
	}
	return 0;
}