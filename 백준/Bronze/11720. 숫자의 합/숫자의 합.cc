#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main() {

	int N;
	cin >> N;

	string temp;
	cin >> temp;

	int sum = 0;
	for (int i = 0; i < N; i++) {
		sum += int(temp[i] - '0');
	}

	cout << sum;

	return 0;
}