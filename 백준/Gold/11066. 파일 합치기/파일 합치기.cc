#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int T, K;
int dp[502][502];
int prefixSum[502];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);       
    cout.tie(0);

    cin >> T;
    while(T--) {
        cin >> K;
        vector<int> files;
        files.resize(K + 1);
        for(int i = 1; i <= K; i++) {
            cin >> files[i];
            prefixSum[i] = prefixSum[i - 1] + files[i];
        }

        for(int size = 1; size < K; size++) {
            for(int i = 1; i <= K - size; i++) {
                int j = i + size;
                dp[i][j] = INT_MAX;

                for(int mid = i; mid < j; mid++) {
                    dp[i][j] = min(dp[i][j], dp[i][mid] + dp[mid + 1][j] + prefixSum[j] - prefixSum[i - 1]);
                }
            }
        }

        cout << dp[1][K] << '\n';
    }

    return 0;
}

