#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main() {
	
	while (1) {
		string N;
		cin >> N;
		if (N == "0")break;

		int len = N.length();

		bool flag = true;
		for (int i = 0; i < len / 2; i++) {
			if (N[i] != N[len - i - 1]) {
				flag = false;
			}
		}
		if (flag) cout << "yes" << '\n';
		else
		{
			cout << "no" << '\n';
		}

	}



	return 0;
}