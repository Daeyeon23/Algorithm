#include<bits/stdc++.h>
using namespace std;

int N;
int arr[111];
int M;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0;i < N;++i) {
		cin >> arr[i];
	}
	cin >> M;

	int cnt = 0;
	for (int i = 0;i < N;++i) {
		if (arr[i] == M)cnt++;
	}
	cout << cnt;
	return 0;
}
