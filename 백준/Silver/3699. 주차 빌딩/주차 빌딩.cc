#include<bits/stdc++.h>
using namespace std;

int h, l;
int Map[50][50];

struct node {
	int y, x;
};

node Pos[2500];
int Floor[50];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		cin >> h >> l;
		memset(Map, 0, sizeof(Map));
		memset(Pos, 0, sizeof(Pos));
		memset(Floor, 0, sizeof(Floor));

		int MaxN = 0;
		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < l; ++j) {
				cin >> Map[i][j];
				if (Map[i][j] != -1) {
					Pos[Map[i][j]] = { i,j };
					MaxN = max(MaxN, Map[i][j]);
				}
			}
		}

		int ans = 0;

		for (int i = 1; i <= MaxN; ++i) {
			int y = Pos[i].y;
			int x = Pos[i].x;

			int dif = abs(Floor[y] - x);
			if (dif > abs(l - dif))
				dif = abs(l - dif);

			ans += (y * 10 * 2) + dif * 5;
			Floor[y] = x;
		}

		cout << ans << '\n';

	}

	return 0;
}




