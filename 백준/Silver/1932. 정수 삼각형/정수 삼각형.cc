#include <iostream>
using namespace std;

int n;
int dp[501][501];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);       
    cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            cin >> dp[i][j];
        }
    }

    for(int i = 1; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            // 첫번째 숫자인 경우 내려올 수 있는 부모가 하나다.
            if(j == 0) {
                dp[i][j] = dp[i][j] + dp[i - 1][j];
            }
            // 마지막 숫자인 경우 내려올 수 있는 부모가 하나다.
            else if(i == j) {
                dp[i][j] = dp[i][j] + dp[i - 1][j - 1];
            }
            // 양쪽 부모 중 큰 숫자를 선택
            else {
                dp[i][j] = dp[i][j] + max(dp[i - 1][j - 1], dp[i - 1][j]);
            }
        }
    }

    int ans = 0;
    for(int i = 0; i <= n; i++) {
        ans = max(ans, dp[n-1][i]);
    }

    cout << ans;

    return 0;
}

