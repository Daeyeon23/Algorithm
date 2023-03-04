#include<iostream>
#include<algorithm>
using namespace std;

int N, L;
int Line[1001];


int main() {
	cin >> N >> L;

	for (int i = 0;i < N;i++) {
		int x;
		cin >> x;
		Line[x] = 1;
	}
	int cnt = 0;
	for (int i = 1;i <= 1000;i++) {
		if (Line[i] == 0)continue;
		for (int j = 0;j < L;j++) {
			if (i + j > 1000)break;
			Line[i + j] = 0;
		}
		cnt++;
	}
	cout << cnt;
	return 0;
}