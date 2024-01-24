#include <iostream>
using namespace std;
// 도착 지점에 시작 지점의 값을 저장해놓고
// 가장 긴 오름차순 수열의 길이를 구하는 문제
int n;
int maxNumber = 0;
int status[502];
int dp[502];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);       
    cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        int s, e;
        cin >> s >> e;
        status[e] = s;
        dp[e] = 1;

        maxNumber = max(maxNumber, max(s, e));
    }

    for(int i = 2; i <= maxNumber; i++) {
        for(int j = 1; j < i; j++) {
            if(status[i] > status[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= maxNumber; i++) {
        ans = max(ans, dp[i]);
    }

    cout << (n - ans);

    return 0;
}