#include <iostream>
#include <vector>
// 풀이 : 2차원 DP
// DP[i][j] = i번째 아이템을 확인했을 때 j라는 최대무게에서의 최대 가치를 저장한다.
using namespace std;
int N, K, W, V;
vector<pair<int, int>> items; // <무게, 가치> 저장
int dp[102][100002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;
    items.resize(N + 1);
    for(int i = 1; i <= N; i++) {
        cin >> items[i].first >> items[i].second;
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= K; j++) {
            // 담을 수 있는 경우
            if(j >= items[i].first) {
                dp[i][j] = max(dp[i - 1][j - items[i].first] + items[i].second, dp[i - 1][j]);
            }
            // 담을 수 없는 경우
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << dp[N][K];


    return 0;
}

