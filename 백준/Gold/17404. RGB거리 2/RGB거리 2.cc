/*
RGB 거리에서 1번 과 N번도 달라야 하는 조건이 추가됨.
이를 확인하기 위해 1번 색을 고정시키고 3번 DP를 계산하여 마지막에 확인할 때 첫번째 색이랑 같은값은 빼고
최소값을 구하기.
*/

#include<bits/stdc++.h>
using namespace std;

int N;
int color[1010][3];
int DP[1010][3];


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> color[i][j];
		}
	}
	int Ans = 21e8;

	for (int k = 0; k < 3; k++) {
		memset(DP, 0, sizeof(DP));
		for (int i = 0; i < 3; ++i) {
			if (i == k)
				DP[0][i] = color[0][k];
			else
				DP[0][i] = 21e8;
		}
		

		for (int i = 1; i < N; i++) {
			DP[i][0] = min(DP[i - 1][1], DP[i - 1][2]) + color[i][0];
			DP[i][1] = min(DP[i - 1][0], DP[i - 1][2]) + color[i][1];
			DP[i][2] = min(DP[i - 1][0], DP[i - 1][1]) + color[i][2];
		}
		
		for (int i = 0; i < 3; ++i) {
			if (i == k) continue;
			Ans = min(Ans, DP[N - 1][i]);
		}
	}

	cout << Ans;
	return 0;
}