/*
유의할점!
- 벽은 통과 x CCTV는 통과 가능
- CCTV 수 최대 8개

- 5번부터 하면 유리할까 해서 PQ로 정렬해서 5번부터 dfs 돌릴까 했는데
어짜피 전체 탐색해야되서 의미 없을듯.

1. cctv 위치랑 종류 정보 저장해서 dfs로 전체 탐색


*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int diry[4] = {-1, 0, 1, 0}; // 상 우 하 좌 순서
int dirx[4] = {0, 1, 0, -1};

int N; // 세로
int M; // 가로
int Map[10][10];
struct node
{
    int y, x;
    int num;
};
vector<node> v;
int cctvnum;    // cctv 수
int ans = 21e8; // 최소 개수

int CheckZero() // 0 개수 세기
{
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (Map[i][j] == 0)
                cnt++;
        }
    }
    return cnt;
}

void CheckLine(int y, int x, int dir)
{
    int dy = y;
    int dx = x;
    while (1)
    {
        dy += diry[dir];
        dx += dirx[dir];
        if (dy >= N || dy < 0 || dx >= M || dx < 0) // 경계면
            break;
        if (Map[dy][dx] == 6)
            break; // 벽이면 멈추기
        if (Map[dy][dx] != 0)
            continue;    // 다른 cctv 있으면 넘어가기
        Map[dy][dx] = 1; // 감시 체크
    }
}

void dfs(int level)
{
    if (level == cctvnum)
    {
        ans = min(ans, CheckZero());
        return;
    }

    int cctv = v[level].num;

    int SaveMap[10][10] = {0}; // 맵 저장

    if (cctv == 1)
    {
        for (int dir = 0; dir < 4; dir++)
        {

            memcpy(SaveMap, Map, sizeof(Map));

            CheckLine(v[level].y, v[level].x, dir);
            dfs(level + 1);

            memcpy(Map, SaveMap, sizeof(SaveMap));
        }
    }
    else if (cctv == 2)
    {
        for (int dir = 0; dir < 2; dir++) // dir 0, 1만
        {
            memcpy(SaveMap, Map, sizeof(Map));

            CheckLine(v[level].y, v[level].x, dir);
            CheckLine(v[level].y, v[level].x, dir + 2);

            dfs(level + 1);

            memcpy(Map, SaveMap, sizeof(SaveMap));
        }
    }
    else if (cctv == 3)
    {
        for (int dir = 0; dir < 4; dir++)
        {
            memcpy(SaveMap, Map, sizeof(Map));

            CheckLine(v[level].y, v[level].x, dir);
            CheckLine(v[level].y, v[level].x, (dir + 1) % 4);

            dfs(level + 1);

            memcpy(Map, SaveMap, sizeof(SaveMap));
        }
    }
    else if (cctv == 4)
    {
        for (int dir = 0; dir < 4; dir++)
        {
            memcpy(SaveMap, Map, sizeof(Map));

            CheckLine(v[level].y, v[level].x, (dir + 3) % 4);
            CheckLine(v[level].y, v[level].x, dir);
            CheckLine(v[level].y, v[level].x, (dir + 1) % 4);

            dfs(level + 1);

            memcpy(Map, SaveMap, sizeof(SaveMap));
        }
    }
    else if (cctv == 5)
    {
        memcpy(SaveMap, Map, sizeof(Map));

        CheckLine(v[level].y, v[level].x, 0);
        CheckLine(v[level].y, v[level].x, 1);
        CheckLine(v[level].y, v[level].x, 2);
        CheckLine(v[level].y, v[level].x, 3);

        dfs(level + 1);

        memcpy(Map, SaveMap, sizeof(SaveMap));
    }
}

void init()
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> Map[i][j];
            if (Map[i][j] >= 1 && Map[i][j] < 6)
            {
                v.push_back({i, j, Map[i][j]});
            }
        }
    }
    cctvnum = v.size();
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    init();

    dfs(0);

    cout << ans;

    return 0;
}