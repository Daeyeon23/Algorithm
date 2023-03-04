#include <iostream>
using namespace std;

int N;
int x;
int path[100];
int cnt;
bool find_min = false;

void run(int k) {
	if (k == N) {
		if (!find_min) {
			for (int i = 0;i < N;i++) {
				cout << path[i];
			}
			find_min = true;
		}
		
		return;
	}
	if (find_min)return;

	for (int i = 1;i < 4;i++) {
		x = 0;
		path[k] = i;
		bool flag = true;

		while (k - 2 * x - 1 >= 0) {
			cnt = 0;
			for (int j = 0;j <= x;j++) {
				if (path[k - 2 * x - 1 + j] != path[k - x + j]) {
					break;
				}
				if (cnt == x) {
					flag = false;
					break;
				}
				cnt++;
				
			}
			if (!flag)	break;
			x++;
		}
		if (!flag)continue;

		run(k + 1);

		path[k] = 0;


	}
}
int main()
{
	cin >> N;
	run(0);

	return 0;
}