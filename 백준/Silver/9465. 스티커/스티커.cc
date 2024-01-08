#include <iostream>
#include <vector>
// 풀이 : 2차원 DP
// 위의 스티커를 떼는 경우, 아래 스티커를 떼는 경우, 떼지 않는 경우를 모두 나눠 계산한다.
using namespace std;
int n, t;
int dp[3][100002];
// 0 : 위의 스티커를 떼는 경우
// 1 : 아래 스티커를 떼는 경우
// 2 : 떼지 않는 경우

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--) {
        cin >> n;
        vector<int> up;
        vector<int> down;

        up.resize(n);
        down.resize(n);
        for(int i = 0; i < n; i++) {
            cin >> up[i];
        }

        for(int i = 0; i < n; i++) {
            cin >> down[i];
        }

        // 초기화
        dp[0][0] = up[0];
        dp[1][0] = down[0];

        for(int i = 1; i < n; i++) {
            // 위의 스티커를 떼는 경우
            dp[0][i] = max(dp[1][i-1], dp[2][i-1]) + up[i];

            // 아래 스티커를 떼는 경우
            dp[1][i] = max(dp[0][i-1], dp[2][i-1]) + down[i];

            // 떼지 않는 경우
            dp[2][i] = max(dp[0][i-1], dp[1][i-1]);
        }

        int ans = 0;
        for(int i = 0; i < 3; i++) {
            ans = max(ans, dp[i][n-1]);
        }

        cout << ans << '\n';
    }


    return 0;
}

