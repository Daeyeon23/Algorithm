#include<bits/stdc++.h>
using namespace std;

struct node {
	int left;
	int right;
};
node tree[30];
int N;

void init() {
	cin >> N;

	for (int i = 0; i < N; ++i) {
		char a, b, c;
		cin >> a >> b >> c;
		int idx = a - 'A';
		tree[idx].left = b - 'A';
		tree[idx].right = c - 'A';
	}
}

void printorder(int idx, int type) {
	
	if (type == 1) {
		cout << char(idx + 'A');
	}
	if (tree[idx].left != '.' - 'A') {
		printorder(tree[idx].left, type);
	}
	if (type == 0) {
		cout << char(idx + 'A');
	}

	if (tree[idx].right != '.' - 'A') {
		printorder(tree[idx].right, type);
	}
	if (type == 2) {
		cout << char(idx + 'A');
	}

}


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	init();

	printorder(0, 1);
	cout << '\n';
	printorder(0, 0);
	cout << '\n';
	printorder(0, 2);
	cout << '\n';

	return 0;
}