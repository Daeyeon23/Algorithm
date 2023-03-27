/*
	역으로 이동해보자!!
*/

#include<bits/stdc++.h>
using namespace std;

int N;
int K;
int Target;
int arr[1010];
vector<int> Graph[1010];
int DAT[1010];

struct node {
	int pos;
	int cost;
};

void init()
{
	memset(arr, 0, sizeof(arr));
	memset(DAT, 0, sizeof(DAT));
	memset(Graph, 0, sizeof(Graph));
	/*for (int i = 0;i < 1010;++i)
	{
		Graph[i].clear();
	}*/
	cin >> N >> K;
	for (int i = 1;i <= N;++i) {
		cin >> arr[i];
		DAT[i] = arr[i];
	}
	for (int i = 0;i < K;++i) {
		int from, to;
		cin >> from >> to;
		Graph[to].push_back(from);
	}
	cin >> Target;


}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	for (int tc = 0;tc < T;++tc) {
		init();


		queue<node> q;
		q.push({ Target,arr[Target] });
		int ans = arr[Target];

		while (!q.empty()) {
			node now = q.front();
			q.pop();

			if (DAT[now.pos] > now.cost)continue;

			int nowsize = Graph[now.pos].size();

			for (int i = 0;i < nowsize;++i) {
				int next = Graph[now.pos][i];

				int NextCost = now.cost + arr[next];
				if (NextCost <= DAT[next]) continue;
				DAT[next] = NextCost;
				ans = max(ans, NextCost);
				q.push({ next,NextCost });
			}
		}
		cout << ans << '\n';
	}


	return 0;
}