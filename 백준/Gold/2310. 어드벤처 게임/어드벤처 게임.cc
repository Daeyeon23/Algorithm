/*
	1에서 N까지 도달할 수 있는가? -> N번방 도착하면 종료하기.

	방 정보, 이동 경로 저장하기.

	경로 중 자기 방 가는건 저장하지 말자. 필요없음.

	루프 도는걸 방지하기 위해 visited 에 들고 있는 돈을 저장하자. 돈이 더 클 경우에만 갈 수 있도록!

*/

#include<bits/stdc++.h>
using namespace std;

struct node {
	char Room;
	int cost;
};

struct Person {
	int now;
	int money;
};

int N;
node Info[1001];
vector <int> Map[1001];


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (1) {
		// reset
		memset(Info, 0, sizeof(Info));
		for (int i = 0;i < 1001;++i) {
			Map[i].clear();
		}

		// input
		cin >> N;
		if (N == 0)break;

		for (int i = 1;i <= N;++i) {
			cin >> Info[i].Room >> Info[i].cost;
			int temp;
			cin >> temp;
			while (temp > 0) {
				if (temp != i)
					Map[i].push_back(temp);
				cin >> temp;
			}
		}
		int visited[1001] = { 0 };
		fill_n(&visited[0], 1001, -1);

		bool flag = false;

		queue<Person> q;
		if (Info[1].Room == 'L') {
			q.push({ 1,Info[1].cost});
		}
		else if (Info[1].Room == 'T') {
			if (Info[1].cost == 0) // 통행료 0일수도?
				q.push({ 1,0 });
		}
		else {
			q.push({ 1,0 });
		}

		while (!q.empty()) {
			Person now = q.front();
			q.pop();

			// visited 확인하기.
			if (visited[now.now] > now.money) continue;

			if (Info[now.now].Room == 'T') {	// 트롤방
				if (now.money < Info[now.now].cost) continue; // 입장불가
				now.money -= Info[now.now].cost;
			}
			else if (Info[now.now].Room == 'L') {
				if (now.money < Info[now.now].cost) {	// 일정량까지 충전
					now.money = Info[now.now].cost;
				}
			}

			if (now.now == N) {	// 도달시 종료
				flag = true;
				break;
			}

			int Len = Map[now.now].size();

			for (int i = 0;i < Len;++i) {
				int next = Map[now.now][i];

				if (visited[next] >= now.money)continue;
				visited[next] = now.money;
				q.push({ next,now.money });
			}
		}

		if (flag) {
			cout << "Yes\n";
		}
		else
			cout << "No\n";

	}

	return 0;
}
