#include<iostream>
#include<algorithm>
using namespace std;

int N, K;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N >> K;

	int ans =1;

	for (int i = 0;i < K;i++) {
		ans *= (N - i);
	}
	for (int i = 0;i < K;i++) {
		ans /= (K - i);
	}

	cout << ans;
	

	


	return 0;
}