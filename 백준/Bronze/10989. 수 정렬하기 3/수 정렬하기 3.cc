#include<bits/stdc++.h>
using namespace std;

int N;

int arr[10001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;

	for (int i = 0;i < N;++i) {
		int temp;
		cin >> temp;
		arr[temp]++;
	}

	for (int i = 1;i <= 10000;++i) {
		if (arr[i] == 0)continue;
		for (int j = 0;j < arr[i];++j) {
			cout << i << '\n';
		}
	}


	return 0;
}
