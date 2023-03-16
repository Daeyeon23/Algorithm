#include<iostream>
#include<algorithm>
using namespace std;

int DAT[1010];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K;
	cin >> N >> K;

	for (int i = 1;i <= N;i++) {
		DAT[i] = i;
	}

	int idx = 0;

	cout << "<";
	for (int i = 0;i < N;i++) {
		int cnt = 0;
		while (cnt < K) {
			idx++;
			idx = idx % N;
			if (idx == 0) idx = N;

			if (DAT[idx] != 0)cnt++;

		}
		
		cout << DAT[idx];
		if (i != N - 1) {
			cout << ", ";
		}
		DAT[idx] = 0;
	}
	cout << ">";

	return 0;
}