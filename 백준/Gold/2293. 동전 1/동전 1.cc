#include <iostream>
#include <vector>
#include <algorithm>

// 풀이 : 1차원 DP
// 점화식 : DP[j] = DP[j] + DP[j - coins[i]];

using namespace std;
vector<int> coins;
int dp[10001];
int n, k;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    coins.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    dp[0] = 1;

    for(int i = 0; i < n; i++) {
        for(int j = coins[i]; j <= k; j++) {
            dp[j] = dp[j] + dp[j - coins[i]];
        }
    }

    cout << dp[k];
    
    return 0;
}

