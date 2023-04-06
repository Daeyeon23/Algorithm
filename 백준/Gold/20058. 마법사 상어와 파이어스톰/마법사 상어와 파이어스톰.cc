/*
함수
1. 회전하기 (재귀 이용하기)
2. 얼음 감소 (2중 for문 돌기)
3. 남아있는 얼음 합 구하기 (그냥 2중for문 돌기)
4. 가장 큰 덩어리 구하기 (bfs)

*/

#include<bits/stdc++.h>
using namespace std;

int N; // 맵 크기
int Q; // 시전 횟수

struct node {
    int y, x;
};

int diry[4] = { -1,1,0,0 };
int dirx[4] = { 0,0,-1,1 };

int A[70][70];    // 맵
int B[1000];    // 마법 정보
int temp[70][70];

void Turn(int y, int x, int L, int TargetL) {
    if (L == TargetL) { // 회전하기            
        for (int i = 0; i < (1 << L); i++) {
            for (int j = 0; j < (1 << L); j++) {
                temp[j + y][(1 << L) - i + x - 1] = A[i + y][j + x];
            }
        }
        return;
    }

    int k = 1 << (L - 1);

    Turn(y, x, L - 1, TargetL);
    Turn(y + k, x, L - 1, TargetL);
    Turn(y, x + k, L - 1, TargetL);
    Turn(y + k, x + k, L - 1, TargetL);
}

void MeltIce() {
    bool Check[70][70] = { 0 };

    int k = 1 << N;

    for (int i = 1; i <= k; ++i) {
        for (int j = 1; j <= k; ++j) {
            if (A[i][j] == 0)continue;

            int cnt = 0;

            for (int dir = 0; dir < 4; dir++) {
                int dy = i + diry[dir];
                int dx = j + dirx[dir];
                if (dy <= 0 || dy > k || dx <= 0 || dx > k) continue;
                if (A[dy][dx] > 0)cnt++;
            }
            if (cnt >= 3) Check[i][j] = 1;
        }
    }

    for (int i = 1; i <= k; ++i) {
        for (int j = 1; j <= k; ++j) {
            if (Check[i][j] == 0 && A[i][j] > 0)
                A[i][j]--;
        }
    }
}

int sumIce() {
    int k = 1 << N;

    int Sum = 0;
    for (int i = 1; i <= k; ++i) {
        for (int j = 1; j <= k; ++j) {
            Sum += A[i][j];
        }
    }
    return Sum;
}

int FindLarge() {
    int k = 1 << N;
    bool visited[70][70] = { 0 };

    int ans = 0;

    for (int i = 1; i <= k; ++i) {
        for (int j = 1; j <= k; ++j) {
            if (A[i][j] == 0)continue;
            if (visited[i][j] == 1)continue;

            visited[i][j] = 1;
            queue<node> q;
            q.push({ i,j });
            int cnt = 1;
            while (!q.empty()) {
                node now = q.front();
                q.pop();

                for (int dir = 0; dir < 4; dir++)
                {
                    int dy = now.y + diry[dir];
                    int dx = now.x + dirx[dir];
                    if (dy <= 0 || dy > k || dx <= 0 || dx > k)continue;
                    if (visited[dy][dx] == 1 || A[dy][dx] == 0)continue;
                    visited[dy][dx] = 1;
                    cnt++;
                    q.push({ dy,dx });
                }

            }
            ans = max(ans, cnt);
        }
    }

    return ans;
}

void init() {
    cin >> N >> Q;
    for (int i = 1; i <= (1 << N); ++i) {
        for (int j = 1; j <= (1 << N); ++j) {
            cin >> A[i][j];
        }
    }
    for (int i = 0; i < Q; ++i) {
        cin >> B[i];
    }
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    init();
    for (int i = 0; i < Q; ++i) {
        memset(temp, 0, sizeof(temp));
        Turn(1, 1, N, B[i]);
        memcpy(A, temp, sizeof(temp));
        MeltIce();

    }
    cout << sumIce() << "\n";
    cout << FindLarge() << "\n";


    return 0;
}