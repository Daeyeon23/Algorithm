#include<iostream>
#include<algorithm>
using namespace std;

int main() {

	int n;
	cin >> n;

	if (n <= 100 && n >= 90) {
		cout << 'A';
	}
	else if (n >= 80) {
		cout << 'B';
	}
	else if (n >= 70) {
		cout << 'C';
	}
	else if (n >= 60) {
		cout << 'D';
	}
	else if (n >=0)
		cout << 'F';


	return 0;
}