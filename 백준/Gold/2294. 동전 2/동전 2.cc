#include <iostream>
#include <vector>
using namespace std;

int n, k;
vector<int> coins;
int dp[10002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    coins.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    for(int i = 0; i <= k; i++) {
        dp[i] = 1000000000;
    }
    dp[0] = 0;
    for(int i = 0; i < n; i++) {
        for(int j = coins[i]; j <= k; j++) {
            dp[j] = min(dp[j], dp[j - coins[i]] + 1);
        }
    }

    if(dp[k] == 1000000000) {
        cout << -1;
    }
    else {
        cout << dp[k];
    }


    return 0;
}

