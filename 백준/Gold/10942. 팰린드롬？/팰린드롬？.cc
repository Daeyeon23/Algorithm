#include<iostream>
#include<algorithm>
using namespace std;

int N;
int M;
int arr[2020];
int DP[2020][2020];

void init() {
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> arr[i];
	}
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (i == j){
				DP[i][j] = 1;
			}
			else
				DP[i][j] = -1;
		}
	}
	for (int i = 1; i < N; ++i) {
		if (arr[i] == arr[i + 1])
			DP[i][i + 1] = 1;
	}
	
	cin >> M;
}

int solve(int a, int b) {
	if (DP[a][b] != -1) return DP[a][b];

	if (a > b) return 0;

	return DP[a][b] = solve(a + 1, b - 1) & (arr[a] == arr[b]);

 }

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	init();

	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		cout << solve(a, b) << '\n';
	}

	return 0;
}

/*

	1 2 1 3 1 2 1
1	o x o x x x o
2	  o x x x o x
1		o x o x x
3		  o x x x
1			o x o
2			  o x
1				o

i,i는 다 1

i,j에 대해 i+1,j-1이 1인지, i==j인지



*/