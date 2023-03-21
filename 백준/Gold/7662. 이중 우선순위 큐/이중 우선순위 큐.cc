#include<iostream>
#include<algorithm>
#include<queue>
#include<cmath>
#include<unordered_map>
using namespace std;

struct cmd {
	bool operator () (long long left, long long right) {
		return left > right;
	}
};

struct cmd2 {
	bool operator () (long long left, long long right) {
		return left < right;
	}
};




int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long T;
	cin >> T;

	for (long long tc = 0;tc < T;++tc) {
		long long k;
		cin >> k;

		priority_queue<long long, vector<long long>, cmd> pq;
		priority_queue<long long, vector<long long>, cmd2> pq2;
		unordered_map<long long, long long> um;

		long long insertnum = 0;
		long long deletenum = 0;

		for (long long i = 0;i < k;++i) {
			char temp;
			long long num;
			cin >> temp >> num;
			if (temp == 'I') {
				insertnum++;
				pq.push(num);
				pq2.push(num);
				if (um.find(num) == um.end()) {
					um.insert({ num,1 });
				}
				else {
					um[num]++;
				}
			}
			else if (temp == 'D') {
				
				if (num == 1) {

					while (1) {
						if (pq2.empty()) break;
						long long now = pq2.top();
						pq2.pop();
						if (um[now] != 0) {
							deletenum++;
							um[now]--;
							break;
						}
					}

				}
				else if (num == -1) {

					while (1) {
						if (pq.empty()) break;
						long long now = pq.top();
						pq.pop();
						if (um[now] != 0) {
							deletenum++;
							um[now]--;
							break;
						}
					}

				}
			}
		}

		if (insertnum > deletenum) {
			long long Max;
			while (!pq2.empty()) {
				long long now = pq2.top();
				pq2.pop();
				if (um[now] != 0) {
					Max = now;
					break;
				}
			}
			long long Min;
			while (!pq.empty()) {
				long long now = pq.top();
				pq.pop();
				if (um[now] != 0) {
					Min = now;
					break;
				}
			}


			cout << Max << ' ' << Min << '\n';
		}
		else {
			cout << "EMPTY" << '\n';
		}
	}





	return 0;
}