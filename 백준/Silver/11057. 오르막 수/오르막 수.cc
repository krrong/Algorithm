#include <iostream>

// 풀이 : 2차원 DP?
// 1000(자리수) * 10(끝나는 수) -> 만들 수 있는 수

//    0  1  2  3  4  5  6  7   8   9
// 0  0  0  0  0  0  0  0  0   0   0
// 1  1  1  1  1  1  1  1  1   1   1
// 2  1  2  3  4  5  6  7  8   9   10
// 3  1  3  6 10 15 21 28 36  45   55 
// 4  1  
// 5  1  
// 6  1  
// 7  1  
// 8  1  
// 9  1  

using namespace std;
int N;
long long int dp[1002][10];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for(int i = 0; i < 10; i++) {
        dp[1][i] = 1;
    }

    for(int i = 2; i <= N; i++) {      // 자리수
        for(int j = 0; j < 10; j++) {  // 끝나는 수
            if(j == 0) {
                dp[i][j] = 1;
                continue;
            }

            dp[i][j] = (dp[i][j - 1] % 10007 + dp[i - 1][j] % 10007) % 10007;
        }
    }

    int res = 0;
    for(int i = 0; i < 10; i++) {
        res = (res % 10007 + dp[N][i] % 10007) % 10007;
    }

    cout << res;

    return 0;
}