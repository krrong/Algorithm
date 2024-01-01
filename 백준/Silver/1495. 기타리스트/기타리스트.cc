#include <iostream>
#include <vector>
// 풀이 : 2차원 DP

using namespace std;
int N, M, S, ans = -1;
vector<int> v;
int dp[52][1002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> S >> M;
    v.resize(N + 1);
    for(int i = 1; i <= N; i++) {
        cin >> v[i];
    }
    
    dp[0][S] = 1;
    for(int i = 1; i <= N; i++) {
        for(int j = 0; j <= M; j++) {
            // 연주할 수 있는 볼륨을 찾은 경우 다음 곡 탐색
            if(dp[i - 1][j] == 1) {
                // 볼륨 크기의 합이 범위 안이라면
                if(0 <= j + v[i] && j + v[i] <= M) {
                    dp[i][j + v[i]] = 1;
                }
                if(0 <= j - v[i] && j - v[i] <= M) {
                    dp[i][j - v[i]] = 1;
                }
            }
        }
    }

    for(int i = 0; i <= M; i++) {
        if(dp[N][i] == 1) {
            ans = i;
        }
    }

   cout << ans;

    return 0;
}

