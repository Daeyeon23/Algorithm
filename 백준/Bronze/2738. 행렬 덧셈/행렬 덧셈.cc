#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[101][101];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			int temp;
			cin >> temp;
			arr[i][j] += temp;
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}