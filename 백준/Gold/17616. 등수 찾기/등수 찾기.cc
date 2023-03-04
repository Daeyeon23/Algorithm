#include <iostream>
#include<vector>
#include<cstring>
using namespace std;

int N, M, X;
vector<int>front[100001];
vector<int>back[100001];
bool visited[100001];
int U = 0, V = 0;

void find_front(int a) {

	for (int i = 0; i < back[a].size(); i++) {
		if (!visited[back[a][i]]) {
			visited[back[a][i]] = true;
			U++;
		}
		find_front(back[a][i]);

	}

}

void find_back(int a) {

	for (int i = 0; i < front[a].size(); i++) {

		if (!visited[front[a][i]]) {
			visited[front[a][i]] = true;
			V++;
		}
		find_back(front[a][i]);

	}

}

int main()
{
	cin >> N >> M >> X;

	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		front[x].push_back(y);
		back[y].push_back(x);
	}

	find_front(X);
	cout << 1 + U << ' ';

	memset(visited, 0, sizeof(visited));

	find_back(X);
	cout << N - V;


	return 0;
}