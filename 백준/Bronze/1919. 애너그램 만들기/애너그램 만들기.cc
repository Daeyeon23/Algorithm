#include<bits/stdc++.h>
using namespace std;

int alp1[26];
int alp2[26];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string a, b;
	cin >> a >> b;

	int len1 = a.length();
	int len2 = b.length();

	for (int i = 0; i < len1; ++i) {
		alp1[a[i] - 'a']++;
	}

	for (int i = 0; i < len2; ++i) {
		alp2[b[i] - 'a']++;
	}

	int ans = 0;

	for (int i = 0; i < 26; ++i) {
		if (alp1[i] != alp2[i]) {
			ans += (abs(alp1[i] - alp2[i]));
		}
	}

	cout << ans;

	return 0;
}