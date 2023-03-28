/*
그룹이 지어지는 케이스 : 화살표가 자기에게 돌아오는 경우, 자기자신을 가리킬때.

안지어지는 케이스 : 가리키던 화살표가 자기자신을 가리키는애를 만났을때, 이미 그룹지어진애를 가리킬때

그룹 지어지면 1, 실패하면 -1
*/

#include<bits/stdc++.h>
using namespace std;

int N;	// 학생 수
int arr[100010];
int DAT[100010];
vector<int> path;

void init() {
	memset(arr, 0, sizeof(arr));
	memset(DAT, 0, sizeof(DAT));
	cin >> N;

	for (int i = 1; i <= N; ++i) {
		cin >> arr[i];
	}
}



void dfs(int now, int start) {
	// 그룹 성공!
	if (arr[now] == start) {	
		path.push_back(now);
		int len = path.size();
		for (int i = 0; i < len; ++i) {
			DAT[path[i]] = 1;
		}
		return;
	}

	// 실패할 경우
	if (arr[now] == now || DAT[arr[now]] == 1 || DAT[arr[now]] == -1) {	// 본인 가리킬 경우 or 이미 정해진거 가리킬 경우
		int len = path.size();
		for (int i = 0; i < len; ++i) {
			DAT[path[i]] = -1;
		}
		return;
	}

	if (DAT[arr[now]] == 2) { // 중간꺼를 가리킬때.
		path.push_back(now);
		int Endpos = arr[now];
		
		while (1) {
			int a = path.back();
			path.pop_back();
			DAT[a] = 1;
			if (a == Endpos) break;
		}

		int len = path.size();
		for (int i = 0; i < len; ++i) {
			DAT[path[i]] = -1;
		}
		return;
	}

	// 다른거 가리킬 경우
	path.push_back(now);
	DAT[now] = 2;
	dfs(arr[now], start);


}


void solve() {

	for (int i = 1; i <= N; ++i) {
		if (DAT[i] != 0) continue;	// 이미 정해짐.
		if (DAT[arr[i]] != 0) {	// 이미 그룹지어진애를 가리킬때
			DAT[i] = -1;
			continue;
		}
		if (arr[i] == i) {	// 본인을 가리킬 때.
			DAT[i] = 1;
			continue;
		}
		path.push_back(i);
		dfs(arr[i], i);
		path.clear();
	}
}

int countAns() {
	int cnt = 0;
	for (int i = 1; i <= N; ++i) {
		if (DAT[i] == -1) {
			cnt++;
		}
	}
	return cnt;
}


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {

		init();

		solve();

		cout << countAns() << '\n';
	}



	return 0;
}