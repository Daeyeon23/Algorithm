#include<bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b, c;
	cin >> a >> b >> c;

	cout << (a + b) % c << '\n';
	cout << ((a % c) + (b % c)) % c << '\n';
	cout << (a * b) % c << '\n';
	cout << ((a % c) * (b % c)) % c;



	return 0;
}
