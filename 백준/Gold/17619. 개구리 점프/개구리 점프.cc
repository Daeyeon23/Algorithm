#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N, Q;

struct node {
	int a, b;
	int idx;

	bool operator < (node next)const {
		return a < next.a;
	}
};
node tree[100001];
int parent[100001];

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
}


int main() {
	cin >> N >> Q;

	for (int i = 1;i <= N;i++) {
		parent[i] = i;
	}

	for (int i = 0;i < N;i++) {
		int a, b, y;
		cin >> a >> b >> y;
		tree[i] = { a,b,i+1 };
	}

	sort(tree, tree + N);

	int nowidx = tree[0].idx;
	int cut = tree[0].b;

	for (int i = 1;i < N;i++) {
		if (tree[i].a <= cut) {
			Union(nowidx, tree[i].idx);
			if(cut < tree[i].b)
				cut = tree[i].b;
		}
		else {
			nowidx = tree[i].idx;
			cut = tree[i].b;
		}
	}

	for (int i = 0;i < Q;i++) {
		int a, b;
		cin >> a >> b;
		if (Find(a) == Find(b)) {
			cout << 1 << '\n';
		}
		else {
			cout << 0 << '\n';
		}
	}


	return 0;
}