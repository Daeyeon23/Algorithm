#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	
	int a, b;

	while (1) {
		cin >> a >> b;
		if (cin.eof() == true) {
			break;
		}
		cout << a + b << '\n';
	}



	return 0;
}