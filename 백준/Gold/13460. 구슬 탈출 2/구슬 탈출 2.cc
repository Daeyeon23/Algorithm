#include<bits/stdc++.h>
using namespace std;

int N, M;
char Map[11][11];
char CopyMap[11][11];

bool GameFail = false;	// 파랑공 들어가면
bool GoalIn = false;	// 빨강공 들어가면
int Ans = 11;

void init();
void Gravity();
void Turn90();
void dfs(int level);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	init();
	memcpy(CopyMap, Map, sizeof(Map));
	


	dfs(1);

	if (Ans == 11) cout << -1;
	else cout << Ans;

	return 0;
}

void init() {
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		string temp;
		cin >> temp;
		for (int j = 0; j < M; ++j) {
			Map[i][j] = temp[j];
		}
	}
}


void Gravity() {	// 아래방향으로 내리기

	for (int j = 1; j < 9; ++j) {
		if (CopyMap[0][j] == 0) break;

		bool flag = false;
		int floor = 9;
		int Hole = 10;

		for (int i = 1; i < 10; ++i) {	// R, B 있는지 확인
			if (CopyMap[i][j] == 0) {
				floor = i - 2;
				break;
			}
			if (CopyMap[i][j] == 'R' || CopyMap[i][j] == 'B') {
				flag = true;
			}
		}
		if (!flag) continue;



		for (int i = floor; i > 0; --i) {
			if (CopyMap[i][j] == '#') {
				floor = i - 1;
			}
			else if (CopyMap[i][j] == 'O') {
				Hole = i;
			}
			else if (CopyMap[i][j] == 'R' || CopyMap[i][j] == 'B') {
				if (floor >= Hole) {
					if (CopyMap[i][j] == 'R') {
						GoalIn = true;
						CopyMap[i][j] = '.';
					}
					else {
						GameFail = true;
						return;
					}
				}
				else {
					char temp = CopyMap[i][j];
					CopyMap[i][j] = '.';
					CopyMap[floor--][j] = temp;
				}
			}
		}

		if (GoalIn || GameFail) return;
	}
}

void Turn90() {
	char TempMap[11][11] = { 0 };

	int NowN = 0;

	for (int i = 0; i < 10; ++i) {
		if (CopyMap[i][0] == 0) break;
		NowN++;
	}

	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			if (CopyMap[i][j] == 0) break;
			TempMap[j][NowN - i - 1] = CopyMap[i][j];
		}
	}
	memcpy(CopyMap, TempMap, sizeof(TempMap));
}

void dfs(int level) {
	if (level == 11) {
		return;
	}

	char SaveMap[11][11] = { 0 };


	for (int i = 0; i < 4; ++i) {
		memcpy(SaveMap, CopyMap, sizeof(CopyMap));

		Gravity();

		if (!GameFail && GoalIn) {
			Ans = min(Ans, level);
			GoalIn = false;
			memcpy(CopyMap, SaveMap, sizeof(SaveMap));
			Turn90();
			continue;
		}
		else if (GameFail) {
			GameFail = false;
			GoalIn = false;
			memcpy(CopyMap, SaveMap, sizeof(SaveMap));
			Turn90();
			continue;
		}

		dfs(level + 1);
		memcpy(CopyMap, SaveMap, sizeof(SaveMap));

		Turn90();
	}

}