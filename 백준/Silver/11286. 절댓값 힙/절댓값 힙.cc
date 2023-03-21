#include<iostream>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;

struct cmd {
	bool operator () (int left, int right) {
		if (abs(left) > abs(right))return true;
		if (abs(left) < abs(right))return false;

		return left > right;
	}
};

priority_queue<int, vector<int>,cmd> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0;i < N;i++) {
		int temp;
		cin >> temp;

		if (temp == 0) {
			if (pq.empty()) {
				cout << 0 << '\n';
			}
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else {
			pq.push(temp);
		}
	}



	return 0;
}