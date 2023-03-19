#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int DAT[10];
int N;

int Make9(int num, int e) {
	while (num % 10 != 9) {
		int temp = num;
		while (temp > 0) {
			int now = temp % 10;
			DAT[now] += pow(10, e);
			temp /= 10;
		}
		num--;
	}
	return num;
}



int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	
	int idx = 0;
	while (N > 0) {
		if (N / 10 == 0) {
			while (N > 0) {
				DAT[N] += pow(10, idx);
				N--;
			}
		}
		else {
			N = Make9(N, idx);

			int a = N / 10;

			for (int i = 0; i < 10; i++) {
				DAT[i] += (a + 1) * pow(10, idx);
			}

			N = N / 10;
			idx++;
		}		
	}

	for (int i = 1; i <= idx; i++) {
		DAT[0] -= pow(10, i - 1);
	}


	
	for (int i = 0; i < 10; i++) {
		cout << DAT[i] << ' ';
	}

	return 0;
}