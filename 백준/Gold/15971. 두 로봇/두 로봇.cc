#include <iostream>
#include<vector>
using namespace std;

int N,from,to;
struct way {
	int to;
	int length;
};

vector<way>map[100001];
int path[100000];
int cnt = 0;
bool visited[100001];

void run(int a) {
	if (a == to) {
		int max = 0;
		int sum = 0;
		for (int i = 0;i < N - 1;i++) {
			if (max < path[i]) {
				max = path[i];
			}
			sum += path[i];
		}
		cout << sum - max;
		return;
	}

	for (int i = 0;i < map[a].size();i++) {
		if (visited[map[a][i].to])continue;

		visited[map[a][i].to] = 1;
		path[cnt] = map[a][i].length;
		cnt++;
		run(map[a][i].to);

		visited[map[a][i].to] = 0;
		path[cnt] = 0;
		cnt--;

	}
}

int main()
{
	cin >> N >> from >> to;

	for (int i = 0;i < N - 1;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		map[a].push_back({ b,c });
		map[b].push_back({ a,c });
	}

	visited[from] = 1;
	run(from);

	
	return 0;
}