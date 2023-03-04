#include <iostream>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

int N; 
int visited[10000] = { 0, };

struct Node {
	int num;
	string s;
};

void bfs(int A, int B) {
	queue<Node>q;
	q.push({ A, "" });

	// 최대 4자리 숫자를 기록 
	visited[A] = 1; 

	while (!q.empty()) {
		Node now = q.front();
		q.pop();
		if (now.num == B) {
			cout << now.s << '\n';
			return; 
		}
		//D
		int D = now.num * 2 % 10000;
		if (visited[D] == 0) {
			q.push({ D, now.s + "D" });
			visited[D] = 1; 
		}

		//S
		int S = now.num - 1;
		if (S >= 0) {
			if (visited[S] == 0) {
				q.push({ S, now.s + "S" });
				visited[S] = 1; 
			}
		}
		// now.num == 0 이면 9999로 변환 
		else if (S == -1) {
			q.push({ 9999, now.s + "S" });
			visited[9999] = 1; 
		}

		//L
		int L = now.num % 1000 * 10 + now.num / 1000; 
		if (visited[L] == 0) {
			q.push({ L, now.s + "L" });
			visited[L] = 1; 
		}
		
		//R
		int R = (now.num % 10 * 1000) + (now.num / 10); 
		if (visited[R] == 0) {
			q.push({ R, now.s + "R" });
			visited[R] = 1; 
		}
	}
}


int main() {
	cin >> N; 
	for (int i = 0; i < N; i++) {
		int A, B;
		cin >> A >> B;
		memset(visited, 0, sizeof(visited));
		bfs(A, B); 
	}
}