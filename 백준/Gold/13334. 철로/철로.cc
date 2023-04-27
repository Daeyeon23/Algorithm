#include<bits/stdc++.h>
using namespace std;

int N;
int d;

struct node {
	int start;
	int end;

	bool operator < (node next) const {
		return start > next.start;
	}
};

bool sort_start(node left, node right) {
	return left.end < right.end;
}

vector<node> v;
priority_queue<node> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0;i < N;++i) {
		int a, b;
		cin >> a >> b;
		if (a > b) swap(a, b);

		v.push_back({ a,b });
	}

	cin >> d;

	sort(v.begin(), v.end(), sort_start);

	int Ans = 0; // 최대값

	int Start = -21e8;
	int End = -21e8;

	for (int i = 0;i < N;++i) {

		if (v[i].end - v[i].start > d) continue;

		End = v[i].end;
		Start = End - d;

		pq.push(v[i]);

		while (!pq.empty()) {
			node now = pq.top();
			if (now.start < Start) {
				pq.pop();
			}
			else {
				break;
			}
		}
		int size = pq.size();
		Ans = max(Ans, size);
	}

	cout << Ans;

	return 0;
}
