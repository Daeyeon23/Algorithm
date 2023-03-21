#include<iostream>
#include<algorithm>
using namespace std;

long long N;	// 수의 개수
long long M;	// 수의 변경이 일어나는 횟수
long long K;	// 구간의 합을 구하는 횟수
/*
a,b,c입력
a가 1일경우 b번째 수를 c로 변경
a가 2일경우 b번쨰부터 c까지 합 출력

*/

long long arr[1000010];	// 수 정보 저장
long long tree[4000040];	// 트리


void init() {
	cin >> N >> M >> K;
	for (int i = 0;i < N;++i) {
		cin >> arr[i];
	}
}

// start,end : 더하는 idx 범위. idx : tree 인덱스
long long MakeTree(long long start, long long end, long long idx) {
	// start == end 면 맨 아래까지 왔다는것
	if (start == end) {
		return tree[idx] = arr[start];
	}
	// 반으로 쪼개서 합 구하기
	long long mid = (start + end) / 2;
	return tree[idx] = MakeTree(start, mid, idx * 2) + MakeTree(mid + 1, end, idx * 2 + 1);
}

// start,end: 해당 노드의 합 범위
// left,right: 구하고자 하는 범위 idx : tree 인덱스
long long SumTree(long long start, long long end, long long left, long long right, long long idx) {
	// 범위를 벗어날 경우
	if (right < start || left > end)return 0;

	// 범위안에 들어올경우
	if (left <= start && end <= right) {
		return tree[idx];
	}

	// 범위에서 걸칠 경우
	long long mid = (start + end) / 2;
	return SumTree(start, mid, left, right, idx * 2) + SumTree(mid + 1, end, left, right, idx * 2 + 1);
}

// idx : tree 인덱스, chidx : 바꿀 값 idx, diff : 값 변화량
void ChangeTree(long long start, long long end, long long idx, long long chidx, long long diff) {
	// 범위에 없을 경우
	if (start > chidx || end < chidx) return;

	tree[idx] += diff;
	if (start == end) return;	// 맨 끝 도착!
	long long mid = (start + end) / 2;
	ChangeTree(start, mid, idx * 2, chidx, diff);
	ChangeTree(mid + 1, end, idx * 2 + 1, chidx, diff);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	init();
	
	MakeTree(0,N-1,1);

	for (int i = 0;i < M + K;++i) {
		long long a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			ChangeTree(0, N - 1, 1, b-1, c - arr[b - 1]);
			arr[b - 1] = c;
		}
		else if (a == 2) {
			cout << SumTree(0, N - 1, b - 1, c - 1, 1) << '\n';
		}
	}

	return 0;
}