#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int N; // 줄 길이
int L;	// L 이상 R 이하
int R;	
int Map[60][60];
int parent[3000];
struct node {
	int sum;
	int cnt;
};
node DAT[3000];

int diry[4] = { -1,1,0,0 };
int dirx[4] = { 0,0,-1,1 };

void ResetParent() {	// parent 초기화
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			parent[N * i + j] = N * i + j;
		}
	}
}

int Find(int a) {
	if (a == parent[a])
		return a;

	return parent[a] = Find(parent[a]);
}

void Union(int a, int b) {
	int pa = Find(a);
	int pb = Find(b);

	if (pa == pb)return;

	parent[pb] = pa;
}

int main() {
	cin >> N >> L >> R;

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> Map[i][j];
		}
	}

	bool flag = false;
	int day = 0;
	while (1) {
		flag = false;
		ResetParent();
		memset(DAT, 0, sizeof(DAT));

		for (int i = 0;i < N;i++) {
			for (int j = 0;j < N;j++) {
				int now = Map[i][j];

				for (int dir = 0;dir < 4;dir++) {
					int dy = i + diry[dir];
					int dx = j + dirx[dir];
					if (dx >= N || dx < 0 || dy >= N || dy < 0)continue;
					int diff = abs(Map[dy][dx] - now);

					if (diff >= L && diff <= R) {
						Union(i * N + j, dy * N + dx);
						flag = true;
					}
				}
			}
		}
		for (int i = 0;i < N;i++) {	//같은거 합하고 개수 세기
			for (int j = 0;j < N;j++) {
				DAT[Find(i * N + j)].sum += Map[i][j];
				DAT[Find(i * N + j)].cnt++;
			}
		}

		for (int i = 0;i < N;i++) {	// 갯수만큼 값 나눠주기
			for (int j = 0;j < N;j++) {
				if (DAT[i * N + j].cnt == 0)continue;
				DAT[i * N + j].sum /= DAT[i * N + j].cnt;
			}
		}

		for (int i = 0;i < N;i++) {	// 값 갱신
			for (int j = 0;j < N;j++) {
				Map[i][j] = DAT[Find(i * N + j)].sum;
			}
		}
		if (flag) {
			day++;
		}
		else {
			break;
		}
	}

	cout << day;


	


	return 0;
}