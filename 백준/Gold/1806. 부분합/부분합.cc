#include<bits/stdc++.h>
using namespace std;

int N;	// 수열 길이
int S;	// 목표 합
int arr[100010];

void init() {
	cin >> N >> S;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}
}

int TwoPointer() {
	int left = 0;
	int right = 0;
	int cnt = 1;
	int sum = arr[left];
	int ans = 21e8;
	while (right < N) {
		
		if (sum < S) {
			right++;
			cnt++;
			sum += arr[right];
		}
		else {
			ans = min(ans, cnt);
			sum -= arr[left];
			left++;
			cnt--;
			if (left > right) {
				right = left;
				sum += arr[right];
				cnt = 1;
			}
		}
	}
	return ans;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	int ans = TwoPointer();

	if (ans == 21e8) cout << 0;
	else
	{
		cout << ans;
	}

	return 0;
}