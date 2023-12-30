#include <iostream>
#include <queue>

// 풀이 : BFS
// BFS를 통해 연결된 병사의 수를 구한다

using namespace std;
int N, M, W, B;
int board[102][102];
int visited[102][102];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool isValid(int x, int y) {
    return !(x < 0 || x >= N || y < 0 || y >= M);
}

void bfs(int x, int y, char c) {
    int cnt = 0;
    queue<pair<int, int>> q;
    visited[x][y] = true;
    q.push({x, y});

    while(!q.empty()) {
        cnt++;
        pair<int, int> cur = q.front();
        q.pop();
        int cx = cur.first;
        int cy = cur.second;

        for(int dir = 0; dir < 4; dir++) {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];

            // 유효하지 않은 위치면 pass
            if(!isValid(nx, ny)) continue;

            // 이미 방문했으면 pass
            if(visited[nx][ny]) continue;

            // 다른 병사인 경우 pass
            if(board[nx][ny] != c) continue;

            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }

    if(c == 'W') {
        W += cnt * cnt;
    }
    else {
        B += cnt * cnt;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> M >> N;

    // 초기화
    for(int i = 0; i < N; i++) {
        string tmp;
        cin >> tmp;

        for(int j = 0; j < M; j++) {
            board[i][j] = tmp[j];
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            // 방문하지 않은 곳이라면 bfs 실행
            if(visited[i][j] == false) {
                bfs(i, j, board[i][j]);
            }
        }
    }

    cout << W << ' ' << B;

    return 0;
}

