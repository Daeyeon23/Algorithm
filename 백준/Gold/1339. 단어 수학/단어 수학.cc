#include <iostream>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;

struct node {
	int idx;
	int DAT;

	bool operator < (node next)const {
		return DAT > next.DAT;
	}
};

node Alp[26];
int N;
string Name[10];
int len[10];
int sum;

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> Name[i];
		len[i] = Name[i].length();
		for (int j = 0; j < len[i]; j++) {
			Alp[Name[i][j] - 'A'].DAT += pow(10, len[i] - j - 1);
		}
	}

	for (int i = 0; i < 26; i++) {
		Alp[i].idx = i;
	}

	sort(Alp, Alp + 26);

	int n = 9;

	for (int i = 0; i < 10; i++) {
		if (Alp[i].DAT == 0)break;
		sum += Alp[i].DAT * n--;
	}


	cout << sum;
}