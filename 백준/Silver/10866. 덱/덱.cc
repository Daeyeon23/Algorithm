#include<iostream>
#include<algorithm>
#include<deque>
#include<string>
using namespace std;

deque<int> dq;
int N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;

	for (int i = 0;i < N;i++) {
		string temp;
		cin >> temp;
		int n;
		

		if (temp == "push_front") {
			cin >> n;
			dq.push_front(n);
		}
		else if (temp == "push_back") {
			cin >> n;
			dq.push_back(n);
		}
		else if (temp == "pop_front") {
			if (dq.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << dq.front() << '\n';
				dq.pop_front();
			}
		}
		else if (temp == "pop_back") {
			if (dq.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << dq.back() << '\n';
				dq.pop_back();
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
		else if (temp == "front") {
			if (dq.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << dq.front() << '\n';
			}
		}
		else if (temp == "back") {
			if (dq.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << dq.back() << '\n';
			}
		}
	}

	return 0;
}