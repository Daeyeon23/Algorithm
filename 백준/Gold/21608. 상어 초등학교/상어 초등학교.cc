/*
N은 3~20

우선순위
1. 좋아하는 학생이 인접한 칸에 가장 많을수록.
2. 인접한 칸중 빈칸이 많을수록
3. 행 작을수록, 열 작을수록

알아야할 것 : 학생의 위치

1. 좋아하는 학생이 자리에 배정 되었는지 확인. 그 학생 주위 빈자리에 +1
2. 맵 돌면서 좋아하는 학생수 많을때 갱신, 같으면 빈자리수 확인.
3. 2중 for문 돌면서 자동으로 3번 해결.

+ 마지막에 좋아하는 학생 정보 다시 써야되서 저장해둬야함...

*/

#include<bits/stdc++.h>
using namespace std;

int diry[4] = { -1,1,0,0 };
int dirx[4] = { 0,0,-1,1 };

int N;
int Map[21][21];	// 학생 자리 배정하기
int Check[21][21];	// 자리 확인용
int Pos[401][2];	// 학생 자리 정보 저장
int Student[401][4];	// 좋아하는 정보 저장

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N * N; ++i) {
		memset(Check, 0, sizeof(Check));

		int std;
		cin >> std;

		int Like[4];
		for (int j = 0; j < 4; ++j) {	// 좋아하는 자리 체크
			cin >> Like[j];
			Student[std][j] = Like[j];

			if (Pos[Like[j]][0] == 0 && Pos[Like[j]][1] == 0) continue;

			int y = Pos[Like[j]][0];
			int x = Pos[Like[j]][1];

			for (int dir = 0; dir < 4; ++dir) {
				int dy = y + diry[dir];
				int dx = x + dirx[dir];
				if (dy <= 0 || dy > N || dx <= 0 || dx > N)continue;
				if (Map[dy][dx] != 0)continue;
				Check[dy][dx]++;
			}
		}

		pair<int, int> Fav;	// 선호 자리 저장
		int Max_Peo=-1;	// 좋아하는 사람 수
		int Max_Blank=-1;	// 빈자리 수

 		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				if (Map[i][j] != 0) continue;
				if (Check[i][j] > Max_Peo) {	// 클 경우
					Max_Peo = Check[i][j];
					Fav = { i,j };
					int Now_Blank = 0;
					for (int dir = 0; dir < 4; ++dir) {
						int dy = i + diry[dir];
						int dx = j + dirx[dir];
						if (dy <= 0 || dy > N || dx <= 0 || dx > N)continue;
						if (Map[dy][dx] != 0)continue;
						Now_Blank++;
					}
					Max_Blank = Now_Blank;
				}
				else if (Check[i][j] == Max_Peo) {	// 같을 경우 빈자리수 확인
					int Now_Blank = 0;
					for (int dir = 0; dir < 4; ++dir) {
						int dy = i + diry[dir];
						int dx = j + dirx[dir];
						if (dy <= 0 || dy > N || dx <= 0 || dx > N)continue;
						if (Map[dy][dx] != 0)continue;
						Now_Blank++;
					}
					if (Max_Blank < Now_Blank) {	// 클 경우 갱신
						Fav = { i,j };
						Max_Blank = Now_Blank;
					}
				}


			}
		}
		
		Map[Fav.first][Fav.second] = std;
		Pos[std][0] = Fav.first;
		Pos[std][1] = Fav.second;

	}

	int Ans = 0;

	for (int i = 1 ; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			int std = Map[i][j];

			int cnt = 0;

			for (int dir = 0; dir < 4; ++dir) {
				int dy = i + diry[dir];
				int dx = j + dirx[dir];
				if (dy <= 0 || dy > N || dx <= 0 || dx > N)continue;
				
				int now = Map[dy][dx];

				for (int k = 0; k < 4; ++k) {
					if (now == Student[std][k]) {
						cnt++;
						break;
					}
				}
			}

			if(cnt !=0)
				Ans += pow(10, cnt-1);

		}
	}

	cout << Ans;

	return 0;
}

