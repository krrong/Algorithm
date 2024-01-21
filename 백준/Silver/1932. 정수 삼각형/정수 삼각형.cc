#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> triangle;
int dp[125251];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < i; j++) {
            int tmp;
            cin >> tmp;
            triangle.push_back(tmp);
        }
    }

    int a = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < i; j++) {
            dp[a] = triangle[a];
            a++;
        }
    }

    // n층이면 n개가 있는 형태
    // 마지막층 빼고 dp 테이블 순회
    int height = 1;
    for(int i = 0; i < triangle.size() - n; i++) {
        int tmpHeight = height;
        while(tmpHeight--) {
            dp[i + height] = max(dp[i + height], dp[i] + triangle[i + height]);
            dp[i + 1 + height] = max(dp[i + 1 + height], dp[i] + triangle[i + 1 + height]);
            i++;
        }
        i--;
        height++;
    }

    int ans = 0;
    for(int i = triangle.size() - n; i < triangle.size(); i++) {
        ans = max(ans, dp[i]);
    }

    cout << ans;

    return 0;
}

