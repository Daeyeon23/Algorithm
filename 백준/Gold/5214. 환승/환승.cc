#include <iostream>
#include<queue>
#include<vector>
using namespace std;

int N, K, M;

vector<int> map[100001];
vector<int> hyper[1001];
int visited[100001];
int hyper_visited[1001];
int cnt_st = -1;

void bfs() {
	queue<int> q;
	q.push(1);
	visited[1] = 1;

	while (!q.empty()) {
		int now_station = q.front();
		q.pop();
		if (now_station == N) {
			cnt_st = visited[now_station];
			return;
		}

		for (int i = 0;i < map[now_station].size();i++) {
			int now_hyper = map[now_station][i];
			if (hyper_visited[now_hyper])continue;
			hyper_visited[now_hyper] = 1;


			for (int j = 0;j < hyper[now_hyper].size();j++) {
				int new_station = hyper[now_hyper][j];
				if (visited[new_station])continue;
				visited[new_station] = visited[now_station] + 1;
				q.push(new_station);
			}
		}
	}

}


int main()
{
	cin >> N >> K >> M;

	for (int i = 1;i <= M;i++) {
		for (int j = 0;j < K;j++) {
			int a;
			cin >> a;
			hyper[i].push_back(a);
			map[a].push_back(i);
		}
	}

	bfs();
	cout << cnt_st;
	return 0;
}