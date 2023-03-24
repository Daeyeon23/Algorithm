#include<bits/stdc++.h>
using namespace std;

int N;	// 사과나무 수
int arr[100010];	// 나무 높이
int sum = 0;	// 높이 합

int evensum = 0;	// /2한 것들의 합

void init() {
	cin >> N;
	for (int i = 0;i < N;++i) {
		cin >> arr[i];
		sum += arr[i];
		evensum += (arr[i] / 2);		
	}
}

bool solve() {
	if (sum % 3 != 0)return false;

	if (sum/3 > evensum) return false;

	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	init();
	bool ans = solve();

	if (ans) cout << "YES";
	else cout << "NO";

	

	return 0;
}