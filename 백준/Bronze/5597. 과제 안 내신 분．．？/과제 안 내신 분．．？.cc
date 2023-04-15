#include<bits/stdc++.h>
using namespace std;

int arr[31];
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	for (int i = 0; i < 28; ++i) {
		int temp;
		cin >> temp;
		arr[temp] = 1;
	}

	for (int i = 1; i < 31; ++i) {
		if (arr[i] == 1)continue;
		cout << i << '\n';
	}

	return 0;
}