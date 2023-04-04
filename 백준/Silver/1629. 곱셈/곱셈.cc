// (a*b)%c = (a%c * b%c) % c

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int a, b, c;

ll solve(int m) {
	if (m == 0) {
		return 1;
	}

	if (m == 1) {
		return a % c;
	}
	ll temp = solve(m / 2) % c;

	if (m % 2 == 1) { // b가 2면
		return temp * (temp * a % c) % c;
	}
	else {
		
		return temp * temp % c;
	}
}


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> a >> b >> c;

	cout << solve(b);

	return 0;
}




