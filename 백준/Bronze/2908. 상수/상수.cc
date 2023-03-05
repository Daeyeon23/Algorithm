#include<iostream>
#include<algorithm>
using namespace std;

int main() {

	int a[2];
	
	for (int i = 0; i < 2; i++) {
		cin >> a[i];
		int temp = a[i] / 100;
		int temp2 = a[i] / 10 % 10;
		int temp3 = a[i] % 10;

		a[i] = temp + temp2 * 10 + temp3 * 100;
	}
	
	cout << max(a[0], a[1]);

	return 0;
}