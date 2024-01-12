#include <iostream>
#include <vector>

using namespace std;
int dp[1002];
int reverseDp[1002];
int N;
vector<int> nums;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    nums.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> nums[i];
        dp[i] = 1;
        reverseDp[i] = 1;
    }

    // 가장 긴 오름차순 수열 개수를 dp에 저장
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < i; j++) {
            if(nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    // 반대로 봤을 때 가장 긴 오름차순 수열 개수를 dp에 저장
    for(int i = N - 1; i >= 0; i--) {
        for(int j = N - 1; j > i; j--) {
            if(nums[i] > nums[j]) {
                reverseDp[i] = max(reverseDp[i], reverseDp[j] + 1);
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < N; i++) {
        ans = max(ans, dp[i] + reverseDp[i]);
    }

    cout << ans - 1;
    
    return 0;
}

