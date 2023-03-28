#include<bits/stdc++.h>
using namespace std;

int DAT[1000][1000];


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string A;
	string B;
	cin >> A >> B;

	int Alen = A.length();
	int Blen = B.length();

	for (int i = 0;i < Alen;++i) {
		for (int j = 0;j < Blen;++j) {
			if (A[i] == B[j]) {
				if (i == 0 || j == 0) {
					DAT[i][j] = 1;
				}
				else {
					DAT[i][j] = DAT[i - 1][j - 1] + 1;
				}
			}
			else {
				if (i == 0 && j == 0) DAT[i][j] = 0;
				else if (i == 0) {
					DAT[i][j] = DAT[i][j - 1];
				}
				else if (j == 0) {
					DAT[i][j] = DAT[i - 1][j];
				}
				else {
					DAT[i][j] = max(DAT[i - 1][j], DAT[i][j - 1]);
				}
			}
		}
	}

	cout << DAT[Alen - 1][Blen - 1] << '\n';

	stack<char> q;
	

	int start_y = Alen - 1;
	int start_x = Blen - 1;

	while (start_y >= 0 && start_x >= 0) {

		if (DAT[start_y][start_x] == DAT[start_y - 1][start_x]) {
			start_y = start_y - 1;
		}
		else if (DAT[start_y][start_x] == DAT[start_y][start_x-1]) {
			start_x = start_x - 1;
		}
		else {
			q.push(A[start_y]);
			start_y = start_y - 1;
			start_x = start_x - 1;
		}
	}

	while (!q.empty()) {
		char now = q.top();
		q.pop();
		cout << now;
	}

	return 0;
}