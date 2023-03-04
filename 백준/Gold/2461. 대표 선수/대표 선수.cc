#include<iostream>
#include<algorithm>
using namespace std;

int N, M;
int arr[1000][1000];
int pointer[1000];

int main() {
	cin >> N >> M;

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0;i < N;i++) {
		sort(arr[i], arr[i] + M);
	}

	int ans = 21e8;

	while (1) {

		int Min = 21e8;
		int Max = 0;
		int Min_idx = 0;

		for (int i = 0;i < N;i++) {
			if (arr[i][pointer[i]] < Min) {
				Min = arr[i][pointer[i]];
				Min_idx = i;
			}
			if (arr[i][pointer[i]] > Max) {
				Max = arr[i][pointer[i]];
			}
		}

		if (ans > (Max - Min)) {
			ans = Max - Min;
		}

		pointer[Min_idx]++;
		if (pointer[Min_idx] == M) break;

	}

	cout << ans;

	return 0;
}