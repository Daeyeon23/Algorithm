/*
	역으로 이동해보자!!
*/

#include<bits/stdc++.h>
using namespace std;

int N;
int K;
int Target;
int arr[1010];
//vector<vector<int>> Graph;
int Graph[1010][1010];
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
	cin >> N >> K;
	//Graph.clear();
	//Graph.shrink_to_fit();
	
	for (int i = 1;i <= N;++i) {
		cin >> arr[i];
		DAT[i] = arr[i];
	}
	for (int i = 0;i < K;++i) {
		int from, to;
		cin >> from >> to;
		Graph[to][from] = 1;
		//Graph[to].push_back(from);
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

			for (int i = 1;i <= N;++i) {
				if (Graph[now.pos][i] == 0)continue;
				int NextCost = now.cost + arr[i];
				if (NextCost <= DAT[i])continue;
				DAT[i] = NextCost;
				ans = max(ans, NextCost);
				q.push({ i,NextCost });
			}

		}
		cout << ans << '\n';
	}


	return 0;
}