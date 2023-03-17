#include<iostream>
#include<algorithm>
using namespace std;

int DP[1010];
int arr[1010];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0;i < N;i++) {
		cin >> arr[i];
		DP[i] = 1;
	}


	int ans = 1;

	for (int i = 1;i < N;i++) {
		for (int j = i - 1;j >= 0;j--) {
			if (arr[i] > arr[j]) {
				DP[i] = max(DP[i], DP[j] + 1);
			}
		}
		ans = max(ans, DP[i]);
	}
	cout << ans;
	

	return 0;
}