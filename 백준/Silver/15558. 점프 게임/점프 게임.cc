#include <iostream>
#include <queue>
using namespace std;

int N, K;
int map[2][100001];
int visited[2][100001];
int pos;
struct position {
	int idx;
	int floor;
};
bool flag = false;
void bfs() {
	
	queue<position> q;
	
	q.push({ 0,0 });
	visited[0][0] = 1;
	

	while (!q.empty()) {
		position now = q.front();
		q.pop();
		

		position next = { now.idx+1,now.floor };
		if (next.idx >= N) {
			flag = true;
			return;
		}
		if ((map[next.floor][next.idx] == 1) && (visited[next.floor][next.idx] == 0) && next.idx < N) {
			visited[next.floor][next.idx] = visited[now.floor][now.idx] + 1;
			q.push(next);
		}

		next = { now.idx - 1,now.floor };
		if ((map[next.floor][next.idx] == 1) && (next.idx > visited[now.floor][now.idx] - 1) && (visited[next.floor][next.idx] == 0) && (next.idx >=0)) {
			visited[next.floor][next.idx] = visited[now.floor][now.idx] + 1;
			q.push(next);
		}
		
		next.idx = now.idx + K;
		if (next.idx >= N) {
			flag = true;
			return;
		}
		else if (next.idx > N) continue;

		if (now.floor == 1) next.floor = 0;
		else next.floor = 1;

		if ((map[next.floor][next.idx] == 1) && (visited[next.floor][next.idx] == 0) && next.idx < N) {
			visited[next.floor][next.idx] = visited[now.floor][now.idx] + 1;
			q.push(next);
		}

	}



}


int main()
{
	cin >> N >> K;	

	for (int i = 0;i < 2;i++) {
		for (int j = 0;j < N;j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	bfs();



	if (flag)cout << 1;
	else cout << 0;

	return 0;
}