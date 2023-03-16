#include<iostream>
#include<algorithm>
#include<queue>
#include<string>
using namespace std;


struct node {
	int age;
	int idx;
	string name;

	bool operator < (node next)const {
		if( age > next.age) return true;
		if (age < next.age) return false;
		return idx > next.idx;
	}
};
priority_queue<node> pq;

int N; // d

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0;i < N;i++) {
		int age;
		string name;
		cin >> age >> name;

		pq.push({ age,i,name });
	}


	while (!pq.empty()) {
		node now = pq.top();
		pq.pop();

		cout << now.age << ' ' << now.name << '\n';

	}
	return 0;
}