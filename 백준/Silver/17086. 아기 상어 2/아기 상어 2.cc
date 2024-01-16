#include <iostream>
#include <queue>

using namespace std;
// 좌상, 상, 우상, 좌, 우, 좌하, 하, 우하
int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1};
int N, M;
bool visited[52][52];
int board[52][52];
int dist[52][52];

bool valid(int x, int y) {
    return !(x < 0 || x > N || y < 0 || y > M);
}

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    dist[x][y] = 0;

    while(!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        for(int dir = 0; dir < 8; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            // 유효하지 않은 위치
            if(!valid(nx, ny)) continue;

            // 방문하지 않은 곳이면 큐에 추가
            if(visited[nx][ny] == false) {
                visited[nx][ny] = true;
                q.push({nx, ny});
                dist[nx][ny] = min(dist[nx][ny], dist[cur.first][cur.second] + 1);
            }
        }
    }
}

void reset() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            visited[i][j] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> board[i][j];
            dist[i][j] = 1000000000;
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            // 상어가 있는 곳에서 bfs 시작
            if(board[i][j] == 1) {
                bfs(i, j);
                reset();
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            ans = max(ans, dist[i][j]);
        }
    }

    cout << ans;

    return 0;
}

