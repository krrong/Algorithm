#include <iostream>
// 풀이 방법 : 2차원 DP
// 점화식 : DP[i][j] = DP[i][0] + DP[0][j]
// 업데이트를 해줘야 함
// N장을 뽑을 때 최대 금액 = MAX(DP[N][0], DP[N-1][1], DP[N-2][2], ..., DP[2][N-2], DP[1][N-1], DP[0][N])
using namespace std;
int n;
int dp[1002][1002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> dp[0][i];
        dp[i][0] = dp[0][i];
    }

    // DP 테이블 초기화
    for(int i = 1; i <= n; i++) {
        // n장을 뽑을 떄 최대 값 저장
        int nmax = 0;
        for(int j = 0; j <= i; j++) {
            dp[i - j][j] = dp[i - j][0] + dp[0][j];
            nmax = max(nmax, dp[i - j][j]);
        }

        // n장을 뽑을 떄 최대 값 갱신
        dp[i][0] = nmax;
        dp[0][i] = nmax;
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans = max(ans, dp[n - i][i]);
    }

    cout << ans;

    return 0;
}

