#include<iostream>
#include<algorithm>
#include<stack>
#include<string>
using namespace std;

stack<int> dq;
int N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;

	for (int i = 0;i < N;i++) {
		string temp;
		cin >> temp;
		int n;
		

		if (temp == "push") {
			cin >> n;
			dq.push(n);
		}
		else if (temp == "pop") {
			if (dq.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << dq.top() << '\n';
				dq.pop();
			}
		}
		else if (temp == "size") {
			cout << dq.size() << '\n';
		}
		else if (temp == "empty") {
			if (dq.empty()) {
				cout << 1 << '\n';
			}
			else {
				cout << 0 << '\n';
			}
		}
		else if (temp == "top") {
			if (dq.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << dq.top() << '\n';
			}
		}
	}

	return 0;
}