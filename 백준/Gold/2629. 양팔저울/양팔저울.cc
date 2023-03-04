#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int N, Q;
int pend[30];
int Query[100000];
int DAT[200001];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> pend[i];
	}
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		cin >> Query[i];
	}

	int Sum = 0;
	DAT[0] = 1;

	for (int i = 0; i < N; i++) {

		queue<int> q;

		for (int j = 0; j <= Sum; j++) {
			if (DAT[j] == 1) {
				q.push(j + pend[i]);
			}
		}
		Sum += pend[i];

		while (!q.empty()) {
			int now = q.front();
			q.pop();
			DAT[now] = 1;
		}
	}

	for (int i = 0; i < N; i++) {

		queue<int> q;

		for (int j = pend[i]; j <= Sum; j++) {
			if (DAT[j] == 1) {
				q.push(j - pend[i]);
			}
		}

		while (!q.empty()) {
			int now = q.front();
			q.pop();
			DAT[now] = 1;
		}

	}


	//for (int i = 0;i < Sum;i++) {
	//	cout << i << ' ' << DAT[i] << '\n';
	//}

	int cnt = 0;
	for (int i = 0; i < Q; i++) {
		if (DAT[Query[i]] == 1) {
			cout << 'Y' << ' ';
		}
		else {
			cout << 'N' << ' ';
		}
	}

	return 0;
}