#include<bits/stdc++.h>
using namespace std;

int N;

vector<pair<int, int>> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0;i < N;++i) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end());

	int Ans = 0;
	int Start = -21e8;
	int End = -21e8;

	for (int i = 0;i < N;++i) {
		if (End < v[i].first) {
			Ans += (End - Start);

			Start = v[i].first;
		}

		if (End < v[i].second) {
			End = v[i].second;
		}
	}
	Ans += (End - Start);

	cout << Ans;

	return 0;
}
