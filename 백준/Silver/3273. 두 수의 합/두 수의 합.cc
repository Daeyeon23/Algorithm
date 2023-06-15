#include<bits/stdc++.h>
using namespace std;

int Num[100001];
int DAT[1000001];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	for (int i = 0; i < N; ++i) {
		cin >> Num[i];
		DAT[Num[i]] = 1;
	}

	int x;
	cin >> x;
	int ans = 0;

	for (int i = 0; i < N; ++i) {
		if (DAT[Num[i]] == 0)continue;
		if (x < Num[i])continue;
		if (x - Num[i] == Num[i]) continue;
		if (x - Num[i] > 1000000)continue;

		if (DAT[x - Num[i]] == 1)
		{
			ans++;
			DAT[Num[i]] = 0;
			DAT[x - Num[i]] = 0;
		}
	}

	cout << ans;

	return 0;
}