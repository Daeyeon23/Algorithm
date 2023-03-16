#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct node {
	int x,y;

	bool operator < (node next)const {
		if (x < next.x) return true;
		if (x > next.x)return false;
		return y < next.y;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	vector<node> v;
	
	int N;
	cin >> N;

	for (int i = 0;i < N;i++) {
		int x, y;
		cin >> x >> y;

		v.push_back({ x,y });
	}

	sort(v.begin(), v.end());

	for (int i = 0;i < N;i++) {
		cout << v[i].x << ' ' << v[i].y << '\n';
	}
	return 0;
}