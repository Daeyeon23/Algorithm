/*
1. 쏠리는 (중력) 기능만 구현하면 되지 않을까??



*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

int N;
int Map[21][21];
int ans = 0;

void init() {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> Map[i][j];
		}
	}
}

void MoveDown() {	// 아래로 내려보자.
	for (int j = 0; j < N; ++j) {	// 세로로 한줄씩

		vector<int> v;
		for (int i = N-1; i >=0; --i) {	// 0이 아닌 값 저장
			if (Map[i][j] == 0)continue;
			v.push_back(Map[i][j]);
		}

		int v_size = v.size();
		if (v_size == 0)continue;	// 그 줄이 다 0이면 진행할 필요 X

		for (int i = 0; i < v_size-1; ++i) {	// 같은 값 붙어있으면 더해주기
			if (v[i] == v[i + 1]) {
				v[i] *= 2;
				v[i + 1] = 0;
				++i;
			}
		}

		for (int i = 0; i < N; ++i) {	// 0으로 일단 비워주기
			Map[i][j] = 0;
		}

		int idx = 0;
		bool flag = false;
		for (int i = N - 1; i >= 0; --i) {	// 아래서부터 채워주기
			while (v[idx] == 0) {
				idx++;
				if (idx == v_size) {
					flag = true;
					break;
				}
			}
			if (flag)break;
			Map[i][j] = v[idx++];
			if (idx == v_size) break;
		}
	}
}

void MoveUp() {	// 위로 올려보자.
	for (int j = 0; j < N; ++j) {	// 세로로 한줄씩

		vector<int> v;
		for (int i = 0; i <N; ++i) {	// 0이 아닌 값 저장
			if (Map[i][j] == 0)continue;
			v.push_back(Map[i][j]);
		}

		int v_size = v.size();
		if (v_size == 0)continue;	// 그 줄이 다 0이면 진행할 필요 X
		for (int i = 0; i < v_size - 1; ++i) {	// 같은 값 붙어있으면 더해주기
			if (v[i] == v[i + 1]) {
				v[i] *= 2;
				v[i + 1] = 0;
				++i;
			}
		}

		for (int i = 0; i < N; ++i) {	// 0으로 일단 비워주기
			Map[i][j] = 0;
		}

		int idx = 0;
		bool flag = false;
		for (int i = 0; i < N; ++i) {	// 위에서부터 채워주기
			while (v[idx] == 0) {
				idx++;
				if (idx == v_size) {
					flag = true;
					break;
				}
			}
			if (flag)break;
			Map[i][j] = v[idx++];
			if (idx == v_size) break;
		}
	}
}

void MoveLeft() {	// 왼쪽으로 몰려보자.
	for (int i = 0; i < N; ++i) {	// 가로로 한줄씩

		vector<int> v;
		for (int j = 0; j < N; ++j) {	// 0이 아닌 값 저장
			if (Map[i][j] == 0)continue;
			v.push_back(Map[i][j]);
		}

		int v_size = v.size();
		if (v_size == 0)continue;	// 그 줄이 다 0이면 진행할 필요 X
		for (int j = 0; j < v_size - 1; ++j) {	// 같은 값 붙어있으면 더해주기
			if (v[j] == v[j + 1]) {
				v[j] *= 2;
				v[j + 1] = 0;
				++j;
			}
		}

		for (int j = 0; j < N; ++j) {	// 0으로 일단 비워주기
			Map[i][j] = 0;
		}

		int idx = 0;
		bool flag = false;
		for (int j = 0; j < N; ++j) {	// 왼쪽부터 채워주기
			while (v[idx] == 0) {
				idx++;
				if (idx == v_size) {
					flag = true;
					break;
				}
			}
			if (flag)break;
			Map[i][j] = v[idx++];
			if (idx == v_size) break;
		}
	}
}

void MoveRight() {	// 오른쪽으로 몰려보자.
	for (int i = 0; i < N; ++i) {	// 가로로 한줄씩

		vector<int> v;
		for (int j = N-1; j >=0; --j) {	// 0이 아닌 값 저장
			if (Map[i][j] == 0)continue;
			v.push_back(Map[i][j]);
		}

		int v_size = v.size();
		if (v_size == 0)continue;	// 그 줄이 다 0이면 진행할 필요 X
		for (int j = 0; j < v_size - 1; ++j) {	// 같은 값 붙어있으면 더해주기
			if (v[j] == v[j + 1]) {
				v[j] *= 2;
				v[j + 1] = 0;
				++j;
			}
		}

		for (int j = 0; j < N; ++j) {	// 0으로 일단 비워주기
			Map[i][j] = 0;
		}

		int idx = 0;
		bool flag = false;
		for (int j = N-1; j >=0; --j) {	// 오른쪽부터 채워주기
			while (v[idx] == 0) {
				idx++;
				if (idx == v_size) {
					flag = true;
					break;
				}
			}
			if (flag)break;
			Map[i][j] = v[idx++];
			if (idx == v_size) break;
		}
	}
}

int FindMax() {
	int Max = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			Max = max(Max, Map[i][j]);
		}
	}
	return Max;
}

void dfs(int level) {
	if (level == 5) {
		ans = max(ans, FindMax());
		return;
	}

	int SaveMap[21][21];
	memcpy(SaveMap, Map, sizeof(Map));

	MoveUp();
	dfs(level + 1);
	memcpy(Map, SaveMap, sizeof(SaveMap));

	MoveRight();
	dfs(level + 1);
	memcpy(Map, SaveMap, sizeof(SaveMap));

	MoveDown();
	dfs(level + 1);
	memcpy(Map, SaveMap, sizeof(SaveMap));

	MoveLeft();
	dfs(level + 1);
	memcpy(Map, SaveMap, sizeof(SaveMap));

	


}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	dfs(0);
	cout << ans;

	return 0;
}