#include <iostream>
#include <vector>
// 풀이 : DP
// 이전 까지의 합과 현재 값을 더했을 때 양수면 그대로 두고 음수면 0으로 바꾼다.

// 10
// 2 1 -4 3 4 -4 6 5 -5 1
// 2 3  0 3 7  3

using namespace std;
vector<int> num;
int dp[100002];
int N, ans = -1002;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        num.push_back(tmp);
    }

    dp[0] = num[0];

    for(int i = 1; i < N; i++) {
        // 이전까지의 합 + 현재 값
        int sum = dp[i - 1] + num[i];

        // 양수면 계속 더해나감
        if(sum > 0) {
            dp[i] = sum;
        }
        // 음수면 0으로 바꿈
        else {
            dp[i] = 0;
        }
    }

    for(int i = 0; i < N; i++) {
        // 음수만 있는 경우를 위해 음수이고, dp가 0인 위치를 음수로 변경
        if(num[i] < 0 && dp[i] == 0) {
            dp[i] = num[i];
        }
        ans = max(ans, dp[i]);
    }

    cout << ans;

    return 0;
}

