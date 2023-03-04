#include<iostream>
#include<algorithm>
using namespace std;


int N;
struct node {
	int a;
	int b;

	bool operator < (node next) const {
		return a < next.a;
	}
};

node P[100000];

int main() {
	int T;
	cin >> T;
	
	for (int t = 0; t < T; t++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> P[i].a >> P[i].b;
		}
		sort(P, P + N);

		int cnt = 1;
		int now_inter = P[0].b;

		for (int i = 1; i < N; i++) {

			if (P[i].b < now_inter) {
				cnt++;
				now_inter = P[i].b;
				if (now_inter == 1)break;
			}
		}
		cout << cnt << '\n';
	}
	


	return 0;
}
