#include <iostream>
#include <vector>

// 풀이 : DP
// DP[i] = I일에 벌 수 있는 최대 금액

using namespace std;
int N, ans = 0;
int dp[17];
vector<pair<int, int>> consultings; // <필요한 날짜, 버는 금액>

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++) {
        int t, p;
        cin >> t >> p;
        consultings.push_back({t, p});
    }

    for(int i = 0; i <= N; i++) {
        // i일까지 버는 돈을 갱신
        dp[i] = max(ans, dp[i]);

        // N일까지의 일을 선택하기 위함
        if(consultings[i].first + i <= N) {
            dp[consultings[i].first + i] = max(dp[consultings[i].first + i], dp[i] + consultings[i].second);
        } 

        // 최대치 갱신
        ans = max(ans, dp[i]);
    }

    cout << ans;

    return 0;
}

