#include <iostream>
using namespace std;

int board[66][66];
bool visited[66][66];

// 게임 승리 여부
bool success = false;

// 방향은 아래, 오른쪽 2가지 
int dx[2] = {1, 0};
int dy[2] = {0, 1};

int N;

bool isValid(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N);
}

void DFS(int x, int y) {
    visited[x][y] = true;
    if(success) return;

    // 2가지 방향으로 이동
    for(int dir = 0; dir < 2; dir++) {
        // 가중치 곱
        int mx = x + board[x][y] * dx[dir];
        int my = y + board[x][y] * dy[dir];

        // 보드판 외부인 경우 더 깊이 탐색하지 않음
        if(!isValid(mx, my)) continue;

        // 방문한 경우 더 깊이 탐색하지 않음
        if(visited[mx][my]) continue;

        // 목적지면 게임 승리 체크
        if(board[mx][my] == -1) {
            success = true;
            return;
        }

        DFS(mx, my);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    DFS(0, 0);
    if(success) {
        cout << "HaruHaru";
    } 
    else {
        cout << "Hing";
    }

    return 0;
}