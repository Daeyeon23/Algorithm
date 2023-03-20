/*
주의사항!
1. 현재 위치에서 제일 가까운 승객 태우기.
2. 거리가 같으면 행 작은순, 같으면 열 작은순!
3. 출발지에서 목적지까지 도달할 수 없을수도있음!
4. 하나의 도착지와 다른 출발지가 같을 수 있음
5. 출발지랑 도착지가 같을 수도 있으므믕리ㅏ마ㅣㄻ위ㅏㅁㄹㅇ뉨ㅇㄴ라ㅜ
6. 현재위치에서 택시로 도달할 수 없는 경우도 체크........

풀이
1. node (출발위치, 도착위치, 거리) 생성해서 미리 출발지부터 도착지까지 거리 구해두기.
2. 현재위치에서 각 출발지까지의 최단거리 함수. -> floodfill이용한 후 정렬(거리,y,x순서)
*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

int diry[4] = { -1,1,0,0 };
int dirx[4] = { 0,0,-1,1 };

int N;	// 한 변 길이
int M;	// 사람 수
int Fuel;	// 연료
int Map[22][22];	// 맵
struct node {
	int start_y;
	int start_x;
	int end_y;
	int end_x;
	int dist;	// 거리
	int idx;	// 택시 번호
	int nowdist;	// 현재위치에서 택시까지 거리

	bool operator < (node next)const {
		if (nowdist < next.nowdist) return true;
		if (nowdist > next.nowdist) return false;
		if (start_y < next.start_y) return true;
		if (start_y > next.start_y) return false;
		return start_x < next.start_x;
	}
};

vector<node> Texi;	// 택시 정보

struct node2 {
	int y, x;
};
node2 StartPos;	// 시작위치

void init() {
	cin >> N >> M >> Fuel;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> Map[i][j];
		}
	}
	cin >> StartPos.y >> StartPos.x;
	StartPos.y--;
	StartPos.x--;

	for (int i = 0; i < M; ++i) {
		int sty, stx, eny, enx;
		cin >> sty >> stx >> eny >> enx;
		Texi.push_back({ sty - 1,stx - 1,eny - 1,enx - 1,0,i });	// 입력 좌표가 1부터 시작
	}
}

int SolveDist(node now) {	//출발지에서 도착지까지 거리 구하기
	int SolveMap[22][22];
	memcpy(SolveMap, Map, sizeof(Map));

	queue<node2> q;
	q.push({ now.start_y,now.start_x });
	SolveMap[now.start_y][now.start_x] = 1;
	while (!q.empty()) {
		node2 Now = q.front();
		q.pop();

		for (int dir = 0; dir < 4; ++dir) {
			int dy = Now.y + diry[dir];
			int dx = Now.x + dirx[dir];
			if (dy >= N || dy < 0 || dx >= N || dx < 0)continue;
			if (SolveMap[dy][dx] != 0)continue;
			SolveMap[dy][dx] = SolveMap[Now.y][Now.x] + 1;
			q.push({ dy,dx });
		}
	}

	return SolveMap[now.end_y][now.end_x] - 1;
}

int FindShort(node2 now) {

	int SolveMap[22][22];
	memcpy(SolveMap, Map, sizeof(Map));

	queue<node2> q;
	q.push({ now.y,now.x });
	SolveMap[now.y][now.x] = 1;
	while (!q.empty()) {
		node2 Now = q.front();
		q.pop();

		for (int dir = 0; dir < 4; ++dir) {
			int dy = Now.y + diry[dir];
			int dx = Now.x + dirx[dir];
			if (dy >= N || dy < 0 || dx >= N || dx < 0)continue;
			if (SolveMap[dy][dx] != 0)continue;
			SolveMap[dy][dx] = SolveMap[Now.y][Now.x] + 1;
			q.push({ dy,dx });
		}
	}
	 
	vector<node> v; 

	for (int i = 0; i < M; ++i) {
		if (Texi[i].dist == -1)continue;
		if (SolveMap[Texi[i].start_y][Texi[i].start_x] == 0)continue;
		Texi[i].nowdist = SolveMap[Texi[i].start_y][Texi[i].start_x] - 1;
		v.push_back(Texi[i]);
	}
	sort(v.begin(), v.end());

	if (v.size() == 0) return -1;
	else
	{
		return v[0].idx;	// 몇번째 택시가 가장 가까운지 리턴
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	init();

	bool flag = true;

	for (int i = 0; i < M; ++i) {
		Texi[i].dist = SolveDist(Texi[i]);
		if (Texi[i].dist == -1) {
			flag = false;
			break;
		}
	}

	
	for (int i = 0; i < M; ++i) {
		if (!flag)break;


		int NextTexi = FindShort(StartPos);
		if (NextTexi == -1) {
			flag = false;
			break;
		}
		if (Texi[NextTexi].dist == 0) {
			Texi[NextTexi].dist = -1;
			StartPos = { Texi[NextTexi].end_y,Texi[NextTexi].end_x };
			continue;
		}
		
		Fuel = Fuel - Texi[NextTexi].nowdist - Texi[NextTexi].dist;
		if (Fuel < 0) {
			flag = false;
			break;
		}
		Fuel += Texi[NextTexi].dist * 2;
		Texi[NextTexi].dist = -1;
		StartPos = { Texi[NextTexi].end_y,Texi[NextTexi].end_x };
	}

	if (flag) {
		cout << Fuel;
	}
	else {
		cout << -1;
	}

	return 0;
}