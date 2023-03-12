#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	vector<int> v;

	for (int i = 0;i < N;i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());

	cout << v[0] << '\n';
	for (int i = 1;i < N;i++) {
		if (v[i - 1] == v[i])continue;
		cout << v[i] << '\n';
	}
	return 0;
}