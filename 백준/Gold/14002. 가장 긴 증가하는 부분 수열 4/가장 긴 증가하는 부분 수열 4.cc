#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

int arr[1000001];
int DAT[1000001];
vector<int> dp;

bool Check(int now, int idx) {

    if (now <= dp[idx]) return true;
    else
    {
        return false;
    }

}

int findnum(int now) {
    int left = 0;
    int right = dp.size() - 1;


    int ans = 0;
    while (left <= right) {
        int Mid = (left + right) / 2;

        if (Check(now, Mid)) {
            right = Mid - 1;
            ans = Mid;
        }
        else {
            left = Mid + 1;
        }
    }
    return ans;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    dp.push_back(arr[0]);

    for (int i = 1; i < N; i++) {
        if (dp.back() < arr[i]) {
            dp.push_back(arr[i]);
            DAT[i] = dp.size() - 1;
        }
        else {
            int idx = findnum(arr[i]);
            if (idx == -1) {
                dp[0] = arr[i];
                DAT[i] = 0;
            }
            else {
                dp[idx] = arr[i];
                DAT[i] = idx;
            }
        }
    }
    cout << dp.size() << '\n';
    int start = dp.size() - 1;

    stack<int> q;

    for (int i = N - 1;i >= 0;--i) {
        if (DAT[i] == start) {
            q.push(arr[i]);
            start--;
        }
        
        if (start == -1)break;
    }

    while (!q.empty()) {
        cout << q.top() << ' ';
        q.pop();
    }

    return 0;
}
