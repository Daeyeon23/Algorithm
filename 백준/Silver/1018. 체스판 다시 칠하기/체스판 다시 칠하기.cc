#include<iostream>
#include<algorithm>
using namespace std;

int Map[50][50];

int main() {
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++) {
			char temp;
			cin >> temp;
			if (temp == 'W') {
				Map[i][j] = 0;
			}
			else {
				Map[i][j] = 1;
			}
		}
	}

	int Min = 21e8;
	
	for (int i = 0; i <= N - 8; i++)
	{
		for (int j = 0; j <= M - 8; j++) {
			for (int k = 0; k < 2; k++) {
				int cnt = 0;
				for (int m = 0; m < 8; m++) {
					for (int n = 0; n < 8; n++) {

						int check = (m + n + k) % 2;
						if (Map[i + m][j + n] != check) {
							cnt++;
						}
					}
				}
				Min = min(cnt, Min);
			}
		}
	}

	cout << Min;

	return 0;
}