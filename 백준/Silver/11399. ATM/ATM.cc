#include<iostream>
#include<algorithm>
using namespace std;

int N;
int Pi[1000];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> Pi[i];
	}
	sort(Pi, Pi + N);

	int sum = 0;
	int sumtime = 0;

	for (int i = 0; i < N; i++) {
		sumtime += Pi[i];
		sum += sumtime;
	}

	cout << sum;
	return 0;
}