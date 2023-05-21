#include<bits/stdc++.h>
using namespace std;

int n;

int Inorder[100001];
int Postorder[100001];
int Pos[100001];

void init();
void Solve(int InStart, int InEnd, int PostStart, int PostEnd);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	init();

	Solve(0, n - 1, 0, n - 1);



	return 0;
}

void init() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> Inorder[i];
		Pos[Inorder[i]] = i;
	}
	for (int i = 0; i < n; ++i) {
		cin >> Postorder[i];
	}
}

void Solve(int InStart, int InEnd, int PostStart, int PostEnd) {

	int Root = Postorder[PostEnd];
	int RootPos = Pos[Root];
	cout << Root << ' ';

	int leftcnt = RootPos - InStart;
	int rightcnt = InEnd - RootPos;

	if (InStart == InEnd) return;

	if(InStart <= RootPos -1)
		Solve(InStart, RootPos - 1, PostStart, PostStart + leftcnt - 1);
	if (RootPos+1 <= InEnd)
		Solve(RootPos + 1, InEnd, PostStart + leftcnt, PostEnd - 1);
}