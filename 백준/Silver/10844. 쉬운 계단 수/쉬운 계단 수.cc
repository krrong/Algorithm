#include <iostream>
// 풀이 : 2차원 DP
// DP[자리수][시작숫자] => DP[2][3]의 의미는 2자리 숫자 중 3으로 시작하는 숫자의 계단 수
// 자리수가 0인 경우 모두 0으로 채운다.
// 자리수가 1인 경우 모두 1로 채운다. (0)
// 자리수가 2이 이상부터는 시작 숫자가 0인 곳을 한 자리수가 적고 1로 시작하는 개수를 가져온다.
// 점화식 : dp[a][b] = dp[a-1][b-1] + dp[a-1][b+1]

using namespace std;
int N;
int dp[101][10];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for(int i = 0; i < 10; i++) {
        dp[1][i] = 1;
    }

    for(int i = 2; i <= N; i++) {
        for(int j = 0; j < 10; j++) {
            if(j == 0) {
                dp[i][j] = dp[i - 1][1];
            }
            else if(j == 9) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = ((dp[i - 1][j - 1]) % 1000000000 + (dp[i - 1][j + 1]) % 1000000000) % 1000000000;
            }
        }
    }

    int ans = 0;
    for(int i = 1; i < 10; i++) {
        ans = (ans + dp[N][i]) % 1000000000;
    }

    cout << ans;

    return 0;
}

