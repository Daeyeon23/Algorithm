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
				if (i == 0 || j==0) {
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

	cout << DAT[Alen - 1][Blen - 1];

	return 0;
}