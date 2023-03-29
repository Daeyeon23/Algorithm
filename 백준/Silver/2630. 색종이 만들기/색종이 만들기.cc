#include<bits/stdc++.h>
using namespace std;

int N;
int Map[130][130];
int White;
int Blue;

void init() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> Map[i][j];
        }
    }
}

bool Check(int startY, int startX, int endY, int endX) {
    int chch = Map[startY][startX];
    
    for (int i = startY; i < endY; ++i) {
        for (int j = startX; j < endX; ++j) {
            if (Map[i][j] != chch) {
                return false;
            }
        }
    }
    return true;
}

void Solve(int startY, int startX, int endY, int endX) {
    if (Check(startY,startX, endY,endX)) {
        if (Map[startY][startX] == 1) Blue++;
        else White++;
        return;
    }
    else {
        int midY = (startY + endY) / 2;
        int midX = (startX + endX) / 2;

        Solve(startY, startX, midY, midX);
        Solve(startY, midX, midY, endX);
        Solve(midY, startX, endY, midX);
        Solve(midY, midX, endY, endX);   
    }



}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    init();

    Solve(0,0,N,N);

    cout << White << '\n' << Blue;



    return 0;
}