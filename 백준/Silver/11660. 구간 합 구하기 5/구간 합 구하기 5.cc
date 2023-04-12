#include<bits/stdc++.h>
using namespace std;

int N;
int M;
int arr[1025][1025];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 1;i <= N;++i) {
		for (int j = 1;j <= N;++j) {
			int num;
			cin >> num;
			arr[i][j] = arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1] + num;
		}
	}

	for (int i = 0;i < M;++i) {
		int y1, x1, y2, x2;
		cin >> y1 >> x1 >> y2 >> x2;
		cout << arr[y2][x2] - arr[y2][x1 - 1] - arr[y1 - 1][x2] + arr[y1 - 1][x1 - 1] << '\n';
	}


	return 0;
}
