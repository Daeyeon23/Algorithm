#include <iostream>
using namespace std;

// index : 열
// value : 사용했는가? 
int DAT[20]; 
// index : / 방향 대각선
// value : 사용했는가? 
int LDRU[100];
// index : \ 방향 대각선
// value : 사용했는가? 
int LURD[100]; 

int N; 
int cnt = 0; 

void func(int row) {
	// 기저조건 -> N-1번 행까지 queen을 두었다면, 하나의 안전한 배치를 찾았다!
	if (row == N) {
		cnt++;
		return; 
	}
	for (int col = 0; col < N; col++) {
		// 만약 col번 열이 사용중이면, 여기는 둘 수 없다. 
		if (DAT[col] == 1)
			continue;

		// 만약 / 방향 대각선에 queen이 있다면, 여기는 둘 수 없다. 
		if (LDRU[col + row] == 1)
			continue; 

		// 만약 \ 방향 대각선에 queen이 있다면, 여기는 둘 수 없다. 
		if (LURD[col - row + N] == 1)
			continue; 
		
		DAT[col] = 1; // row번 행에서 col번 열에 queen 둔다 
		LDRU[col + row] = 1; // / 방향 대각선에 queen이 있다. 
		LURD[col - row + N] = 1; // \ 방향 대각선에 queen이 있다.
		
		func(row + 1); // 다음 행에 queen을 둬본다 
		
		DAT[col] = 0; // row번 행에서 col번에 두었던 queen을 복구 
		LDRU[col + row] = 0; // / 방향 대각선에 둔 queen을 복구 
		LURD[col - row + N] = 0; // \ 방향 대각선에 둔 queen을 복구
	}
}

int main() {
	cin >> N;
	func(0); // 0번 행부터 시작
	cout << cnt;
}