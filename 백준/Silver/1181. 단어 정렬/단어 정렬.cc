#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool cmp(string a, string b) {
	if (a.length() < b.length())return true;
	if (a.length() > b.length())return false;
	return a < b;
}

string str[20000];

int main() {
	int N;
	cin >> N;

	
	for (int i = 0; i < N; i++) {
		cin >> str[i];
	}
	sort(str, str + N, cmp);

	for (int i = 0; i < N; i++) {
		if (str[i] == str[i - 1])continue;
		cout << str[i] << '\n';
	}


	return 0;
}