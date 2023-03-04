#include<vector>
#include<queue>
#include <iostream>
using namespace std;

int N, M;

int visited[200001];

void bfs(int start) {
	queue<int> q;
	q.push(start);
	visited[start] = 1;

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		if (now == M) {
			cout << visited[M]-1;
			return;
		}

		int next = now + 1;
		if (next <= 200000 && visited[next]==0) {
			visited[next] = visited[now] + 1;
			q.push(next);
		}

		next = now * 2;
		if (next <= 200000 && visited[next] == 0) {
			visited[next] = visited[now] + 1;
			q.push(next);
		}

		next = now - 1;
		if (next >= 0 && visited[next] == 0) {
			visited[next] = visited[now] + 1;
			q.push(next);
		}

	}

}


int main()
{	
	cin >> N >> M;
	bfs(N);

	return 0;
}