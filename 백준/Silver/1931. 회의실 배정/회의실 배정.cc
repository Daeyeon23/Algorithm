#include<iostream>
#include<algorithm>
using namespace std;

struct node {
	int a;
	int b;

	bool operator < (node next)const {
		if (b < next.b)return true;
		if (b > next.b)return false;
		return a < next.a;
	}
};
int N;

node schedule[100000];

int main() {
	cin >> N;


	for (int i = 0; i < N; i++) {
		cin >> schedule[i].a >> schedule[i].b;
	}
	sort(schedule, schedule + N);

	int cnt = 0;
	int t = 0;


	for (int i = 0; i < N; i++) {
		if (schedule[i].a < t) continue;
		t = schedule[i].b;
		cnt++;
	}


	cout << cnt;


	return 0;
}