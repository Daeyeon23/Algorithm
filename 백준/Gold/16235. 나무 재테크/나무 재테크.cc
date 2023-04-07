/*
1. 어린 나무부터 자기 나이만큼 양분 흡수. 못먹으면 쥬금
2. 죽은 나무 나이 /2 만큼 양분이 됨.
3. 5의 배수인 나무들 주변에 1살 나무가 생김
4. 양분 추가
*/
#include<bits/stdc++.h>
using namespace std;

int N; // 맵 크기
int M; // 나무 수
int K; // 년수

int Map[11][11];	// 현재 양분 정보
int nourish[11][11];	// 양분 정보 저장

int diry[8] = { -1,-1,-1,0,1,1,1,0 };
int dirx[8] = { -1,0,1,1,1,0,-1,-1 };

vector<int> TreeMap[11][11];	
vector<int> NewTreeMap[11][11];	


void init();
void GrowUp();
void Spread();
void AddNour();
int solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	init();

	for (int k = 0;k < K;++k)
	{
		GrowUp();
		Spread();
		AddNour();

		for (int i = 0;i < N;i++) {
			for (int j = 0;j < N;++j) {
				TreeMap[i][j] = NewTreeMap[i][j];
			}
		}
		
		for (int i = 0;i < N;i++) {
			for (int j = 0;j < N;++j) {
				NewTreeMap[i][j].clear();
			}
		}
	}

	cout << solve();

	return 0;
}


void init() {
	cin >> N >> M >> K;
	for (int i = 0;i < N;++i) {
		for (int j = 0;j < N;++j) {
			cin >> nourish[i][j];
			Map[i][j] = 5;
		}
	}

	for (int i = 0;i < M;++i) {
		int x, y, z;
		cin >> x >> y >> z;
		TreeMap[x-1][y-1].push_back(z);
	}
}

void GrowUp() { // 나무 성장 and 죽이기
	for (int i = 0;i < N;++i) {
		for (int j = 0;j < N;++j) {
			if (TreeMap[i][j].size() == 0) continue;
			sort(TreeMap[i][j].begin(), TreeMap[i][j].end());
			bool flag = true; // 양분 부족하면 false
			int len = TreeMap[i][j].size();

			for (int k = 0;k < len;++k) {
				int now = TreeMap[i][j][k];	// 현재 나무 나이

				if (flag) {	// 성장
					if (Map[i][j] < now) { // 양분 부족!
						flag = false;
						k--;	// 이번꺼 다시하게
						continue;
					}

					Map[i][j] -= now;	// 양분 섭취
					NewTreeMap[i][j].push_back(now + 1); // 성장한 나무 넣어주기
				}
				else {	// 죽이기
					Map[i][j] += now / 2;	
				}
			}
		}
	}
}

void Spread() {
	for (int i = 0;i < N;++i) {
		for (int j = 0;j < N;++j) {
			if (NewTreeMap[i][j].size() == 0) continue;
			int len = NewTreeMap[i][j].size();
			
			for (int k = 0;k < len;++k) {
				int now = NewTreeMap[i][j][k];
				if (now % 5 == 0) {

					for (int dir = 0;dir < 8;dir++) {
						int dy = i + diry[dir];
						int dx = j + dirx[dir];
						if (dy < 0 || dy >= N || dx < 0 || dx >= N)continue;
						NewTreeMap[dy][dx].push_back(1);
					}
				}
			}
		}
	}
}

void AddNour() {
	for (int i = 0;i < N;++i) {
		for (int j = 0;j < N;++j) {
			Map[i][j] += nourish[i][j];
		}
	}
}

int solve() {
	int ans = 0;
	for (int i = 0;i < N;++i) {
		for (int j = 0;j < N;++j) {
			ans += TreeMap[i][j].size();
		}
	}

	return ans;
}