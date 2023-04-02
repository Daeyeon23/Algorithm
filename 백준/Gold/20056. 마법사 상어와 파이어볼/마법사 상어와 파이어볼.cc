#include<bits/stdc++.h>
using namespace std;

int diry[8] = { -1,-1,0,1,1,1,0,-1 };
int dirx[8] = { 0,1,1,1,0,-1,-1,-1 };

int N;   // 맵 크기
int M;   // 파이어볼 수
int K;   // 명령 수

struct node {
    int Weight;
    int Speed;
    int Dir;
};

vector<node> Map[55][55];
vector<node> NewMap[55][55];

void init() {
    cin >> N >> M >> K;
    for (int i = 0; i < M; ++i) {
        int r, c, m, s, d;
        cin >> r >> c >> m >> s >> d;
        Map[r][c].push_back({ m,s,d });
    }
}

void solve() {
    memset(NewMap, 0, sizeof(NewMap));

    // 이동하기
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (Map[i][j].size() == 0)continue;

            int MapSize = Map[i][j].size();

            for (int k = 0; k < MapSize; ++k) {
                node now = Map[i][j][k];
                int dy = i + diry[now.Dir] * now.Speed;
                int dx = j + dirx[now.Dir] * now.Speed;
                dy %= N;
                dx %= N;
                if (dy <= 0) dy += N;
                if (dx <= 0) dx += N;
                NewMap[dy][dx].push_back({ now });
            }
        }
    }

    // 합치기
    memset(Map, 0, sizeof(Map));

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            int FireNum = NewMap[i][j].size();
            if (FireNum == 0)continue;
            else if (FireNum == 1) {
                Map[i][j].push_back({ NewMap[i][j][0] });
                continue;
            }
            
            int FireWeight = 0;
            int FireSpeed = 0;
            int FireDir = NewMap[i][j][0].Dir % 2;
            bool Dirodd = true;

            for (int k = 0; k < FireNum; ++k) {
                node now = NewMap[i][j][k];
                FireWeight += now.Weight;
                FireSpeed += now.Speed;
                if (now.Dir % 2 != FireDir) {
                    Dirodd = false;
                }
            }

            FireWeight /= 5;
            if (FireWeight == 0)continue;
            FireSpeed /= FireNum;
            

            if (Dirodd) {
                for (int d = 0; d < 8; d += 2) {
                    Map[i][j].push_back({ FireWeight,FireSpeed,d });
                }
            }
            else {
                for (int d = 1; d < 8; d += 2) {
                    Map[i][j].push_back({ FireWeight,FireSpeed,d });
                }
            }
        }
    }

}

int SumFire() {
    int Sum = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (Map[i][j].size() == 0)continue;

            int MapSize = Map[i][j].size();

            for (int k = 0; k < MapSize; ++k) {
                node now = Map[i][j][k];
                Sum += now.Weight;
            }
        }
    }
    return Sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    init();
    for (int i = 0; i < K; ++i) {
        solve();
    }
 
    cout << SumFire();

    return 0;
}