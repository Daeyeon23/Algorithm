/*
1. 모든 사람과 계단 사이 거리 구하기.
2. dfs 이용해서 계단 이용 가능한 모든 조합 구하기. (1번 사람- 1번계단, 2번사람- 1번 계단, 3번사람 - 2번 계단, ...)
3. 각 경우에 대해 pq 이용하여 모든 사람이 계단 내려오는데 걸리는 시간 구하기.

*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N; // 방 한변 길이
int Map[11][11];
int Dist[11][2]; // 계단 2개에 대한 거리
int ans;
int P; // 사람 수
int Group[11];
int tc;
struct node
{ // 사람 정보
    int y, x;
};
vector<node> people;

struct stair
{ // 계단 정보
    int y, x;
    int height;
};
vector<stair> stairs;



void CheckDist()
{ // 모든 거리 계산

    for (int i = 0; i < people.size(); i++)
    {
        int y = people[i].y;
        int x = people[i].x;

        for (int j = 0; j < 2; j++)
        {
            int sty = stairs[j].y;
            int stx = stairs[j].x;

            Dist[i][j] = abs(y - sty) + abs(x - stx); // 사람과 계단 거리 계산
        }
    }
}

int solve() {
    vector<int> GroupA;
    vector<int> GroupB;

    for (int i = 0;i < P;i++) {
        if (Group[i] == 1) {
            GroupA.push_back(Dist[i][1]);
        }
        else {
            GroupB.push_back(Dist[i][0]);
        }
    }

    sort(GroupA.begin(), GroupA.end());
    sort(GroupB.begin(), GroupB.end());

    int DATA[11] = { 0 };
    int DATB[11] = { 0 };

    for (int i = 0;i < GroupA.size();i++) {
        if (i < 3) {
            DATA[i] = GroupA[i] + stairs[1].height + 1;
        }
        else {
            if (DATA[i - 3] > GroupA[i]) {
                DATA[i] = DATA[i - 3] + stairs[1].height;
            }
            else {
                DATA[i] = GroupA[i] + stairs[1].height + 1;
            }
        }
    }


    for (int i = 0;i < GroupB.size();i++) {
        if (i < 3) {
            DATB[i] = GroupB[i] + stairs[0].height + 1;
        }
        else {
            if (DATB[i - 3] > GroupB[i]) {
                DATB[i] = DATB[i - 3] + stairs[0].height;
            }
            else {
                DATB[i] = GroupB[i] + stairs[0].height + 1;
            }
        }
    }
    
    if (GroupA.size() == 0) return DATB[GroupB.size() - 1];
    else if (GroupB.size() == 0) return DATA[GroupA.size() - 1];
    else return max(DATA[GroupA.size() - 1], DATB[GroupB.size() - 1]);
}

void dfs(int level)
{ // dfs 이용해서 모든 계단 이용하는 경우의 수
    if (level == P)
    {
        int prob = solve();
        ans = min(ans, prob);
        return;
    }

    for (int i = 0; i < 2; i++)
    {

        Group[level] = i;
        dfs(level + 1);

    }
}

int main()
{
    int T;
    cin >> T;

    for (tc = 1; tc <= T; tc++)
    {
        // reset
        memset(Map, 0, sizeof(Map));
        memset(Dist, 0, sizeof(Dist));
        memset(Group, 0, sizeof(Group));
        people.clear();
        stairs.clear();
        ans = 21e8;

        // input
        cin >> N;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cin >> Map[i][j];

                if (Map[i][j] == 1)
                {
                    people.push_back({ i, j }); // 사람 정보 저장
                }
                else if (Map[i][j] != 0)
                {
                    stairs.push_back({ i, j, Map[i][j] }); // 계단 정보 저장
                }
            }
        }
        P = people.size();

        // solve

        CheckDist();
        dfs(0);

        // output
        cout << "#" << tc << ' ' << ans << '\n';
    }

    return 0;
}