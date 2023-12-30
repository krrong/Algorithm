#include <iostream>
// 풀이 : DP[] -> 증가하는 수의 개수
// N번째 원소를 기준으로 0 ~ N - 1 번째 원소를 돌면서 그 수보다 크면 dp[i] + 1

using namespace std;

int N, ans;
int num[1001];
int dp[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> num[i];
        dp[i] = 1;
    }

    for(int i = 0; i < N; i++) {
        int st = num[i];

        for(int j = 0; j < i; j++) {
            if(num[j] < st) {
                dp[i] = max(dp[j] + 1, dp[i]);
            }
        }
    }

    for(int i = 0; i < N; i++) {
        ans = max(ans, dp[i]);
    }

    cout << ans;

    return 0;
}

