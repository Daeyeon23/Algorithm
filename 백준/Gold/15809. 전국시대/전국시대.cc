#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int N, T;
int DAT[100001];
int parent[100001];
int destroy[100001];

int Find(int now) {
	if (now == parent[now])
		return now;
	return parent[now] = Find(parent[now]);
}

void Union(int a, int b) {
	int pa = Find(a);
	int pb = Find(b);

	if (pa == pb)return;

	parent[pb] = pa;
	DAT[pa] += DAT[pb];
	DAT[pb] = 0;
}



int main() {
	cin >> N >> T;
	for (int i = 1; i <= N; i++) {
		cin >> DAT[i];
		parent[i] = i;
	}


	

	for (int i = 0; i < T; i++) {
		int cmd, a, b;
		cin >> cmd >> a >> b;

		if (cmd == 1)
		{
			Union(a,b);

		}
		else if (cmd == 2) {
			if (DAT[Find(a)] < DAT[Find(b)]) {
				DAT[Find(b)] -= DAT[Find(a)];
				DAT[Find(a)] = 0;
				Union(b, a);
			}
			else if (DAT[Find(a)] > DAT[Find(b)]) {
				DAT[Find(a)] -= DAT[Find(b)];
				DAT[Find(b)] = 0;
				Union(a, b);
			}
			else {
				DAT[Find(a)] = 0;
				DAT[Find(b)] = 0;
			}
		}
	}


	int cnt = 0;
	vector<int> alive;

	for (int i = 1; i <= N; i++) {
		if (DAT[i] != 0) {
			cnt++;
			alive.push_back(DAT[i]);
		}
	}

	cout << cnt << '\n';
	sort(alive.begin(), alive.end());
	
	for (int i = 0; i < alive.size(); i++) {
		cout << alive[i] << ' ';
	}

	return 0;
}