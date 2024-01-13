#include <iostream>
#include <vector>

using namespace std;
int N;
vector<int> nums;
int dp[1002];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    nums.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> nums[i];
        dp[i] = nums[i];
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < i; j++) {
            if(nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + nums[i]);
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < N; i++) {
        ans = max(ans, dp[i]);
    }

    cout << ans;

    return 0;
}

