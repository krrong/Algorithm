#include <iostream>
#include <stack>

using namespace std;
int dp[502][502];
int board[502][502];
int dx[4] = {-1, 1, 0, 0};  // 상하좌우
int dy[4] = {0, 0, -1, 1};
int N, M;

bool valid(int x, int y) {
    return !(x < 1 || x > N || y < 1 || y > M);
}

int dfs(int x, int y) {
    if(x == N && y == M) {
        return 1;
    }

    // 초기값이 아니라면 (이미 거쳐간 경로라면 바로 반환)
    if(dp[x][y] != -1) {
        return dp[x][y];
    }

    dp[x][y] = 0;

    for(int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        // 유효하지 않은 위치면 pass
        if(!valid(nx, ny)) continue;

        if(board[x][y] > board[nx][ny]) {
            dp[x][y] = dp[x][y] + dfs(nx, ny);
        }
    }

    return dp[x][y];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> board[i][j];
            dp[i][j] = -1;
        }
    }

    cout << dfs(1, 1) ;
    
    return 0;
}

