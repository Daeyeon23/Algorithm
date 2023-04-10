/*
nCm = n-1Cm-1 + n-1Cm
*/

#include<bits/stdc++.h>
using namespace std;

int n, m;
string Result;

string DAT[101][101];

string BigAdd(string num1, string num2) {
	Result = "";

	int sum = 0;

	while (!num1.empty() || !num2.empty() || sum) {
		if (!num1.empty()) {
			sum += (num1.back() - '0');
			num1.pop_back();
		}

		if (!num2.empty()) {
			sum += (num2.back() - '0');
			num2.pop_back();
		}

		Result.push_back(sum % 10 + '0');
		sum /= 10;

	}

	reverse(Result.begin(), Result.end());
	return Result;
}

string Combination(int n, int r) {
	if (n == r || r == 0) {
		return "1";
	}

	string result = DAT[n][r];

	if (result != "") {
		return result;
	}

	return DAT[n][r] = BigAdd(Combination(n - 1, r - 1), Combination(n - 1, r));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;

	if (n / 2 < m)
		m = n - m;

	cout << Combination(n, m);

	return 0;
}