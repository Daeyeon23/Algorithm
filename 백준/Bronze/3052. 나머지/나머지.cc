#include<iostream>
#include<algorithm>
using namespace std;

int DAT[42];

int main() {
	int a[10];
	for (int i = 0; i < 10; i++) {
		cin >> a[i];
		int temp = a[i] % 42;
		DAT[temp]++;
	}

	int cnt = 0;
	for (int i = 0; i < 42; i++) {
		if (DAT[i] != 0)cnt++;
	}
	cout << cnt;

	return 0;
}