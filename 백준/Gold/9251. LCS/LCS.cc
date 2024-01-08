#include <iostream>
// 풀이 : 2차원 DP
using namespace std;

int dp[1002][1002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string a, b;
    cin >> a >> b;

    for(int i = 1; i <= a.size(); i++) {
        for(int j = 1; j <= b.size(); j++) {
            // 같은 경우
            if(a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            // 다른 경우
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // for(int i = 0; i <= a.size(); i++) {
    //     for(int j = 0; j <= b.size(); j++) {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    cout << dp[a.size()][b.size()];

    return 0;
}

