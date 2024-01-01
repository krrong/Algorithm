#include <iostream>
#include <vector>

// 풀이 : 2차원 DP
// 포도주는 최대 연속으로 2개까지 마실 수 있다.
// 아래 경우의 수 중 가장 큰 값을 저장한다.

// 1) i 번째 포도주를 마시는 경우
//   - 1] i-1 번째 포도주를 마신 경우
//      : i-3 번째까지 마신 포도주의 총 양 + i-1 번째 포도주의 양 + i 번째 포도주의 양
//          => DP[i-3] + wines[i-1] + wines[i]

//   - 2] i-1 번째 포도주를 마시지 않은 경우
//      : i-2 번째까지 마신 포도주의 총 양 + i 번째 포도주의 양
//          => DP[i-2] + wines[i]

// 2) i 번째 포도주를 마시지 않는 경우
//   : i-1 번째까지 마신 포도주의 양
//      => DP[i-1]

using namespace std;
vector<int> wines;
int dp[100005];
int n;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    wines.push_back(0);
    wines.push_back(0);
    wines.push_back(0);

    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        wines.push_back(tmp);
    }

    for(int i = 3; i < n + 3; i++) {
        int a = dp[i - 3] + wines[i - 1] + wines[i];
        int b = dp[i - 2] + wines[i];
        int c = dp[i - 1];

        int value = max(max(a, b), c);
        dp[i] = value;
    }

    cout << dp[n + 2];

    return 0;
}

