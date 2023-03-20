#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<string>
using namespace std;

int N, M;

unordered_map<string, int> um;
vector<string> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0;i < N;i++) {
		string temp;
		cin >> temp;
		if (um.find(temp) != um.end()) {
			um[temp]++;
		}
		else {
			um.insert({ temp,1 });
		}
	}

	for (int i = 0;i < M;i++) {
		string temp;
		cin >> temp;
		if (um.find(temp) != um.end()) {
			v.push_back(temp);
		}
	}

	sort(v.begin(), v.end());
	cout << v.size() << '\n';

	for (int i = 0;i < v.size();++i) {
		cout << v[i] << '\n';
	}



	return 0;
}