#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	int H, W, N;

	for (int tc = 0;tc < T;tc++) {
		cin >> H >> W >> N;

		int height = N % H;
		if (height == 0) height = H;

		int width = N / H + (N%H !=0);

		cout << height * 100 + width << '\n';
	}
	return 0;
}