#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int Left;
int Right;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;

	for (int tc = 0; tc < T; tc++) {
		string temp;
		cin >> temp;
		Left = 0;
		Right = 0;

		int len = temp.length();
		bool flag = true;
		for (int i = 0; i < len; i++) {
			if (temp[i] == '(') {
				Left++;
			}
			else {
				Right++;
			}
			if (Left < Right) {
				flag = false;
				break;
			}
		}
		if (Left != Right) {
			flag = false;
		}

		if (flag) {
			cout << "YES" << '\n';
		}
		else {
			cout << "NO" << '\n';
		}
	}

	return 0;
}