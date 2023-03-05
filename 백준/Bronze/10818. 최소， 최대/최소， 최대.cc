#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	int Min = 21e8;
	int Max = -21e8;

	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		Min = min(temp, Min);
		Max = max(temp, Max);
	}
	cout << Min << ' ' << Max;



	return 0;
}