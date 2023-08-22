#include <iostream>
using namespace std;

int N, maxHeight, ans;
int area[101][101];
int visited[101][101];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool isValid(int x, int y) {
    return !(x < 0 || x > N || y < 0 || y > N);
}

void DFS(int x, int y) {
    visited[x][y] = true;

    for(int dir = 0; dir < 4; dir++) {
        int mx = x + dx[dir];
        int my = y + dy[dir];

        // 유효한 위치이고, 물에 잠기지 않은 경우에만 이동
        if(isValid(mx, my) && area[mx][my] != 0) {
            if(visited[mx][my]) continue;
            DFS(mx, my);
        }
    }
}

void minusAll() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(area[i][j] != 0) {
                area[i][j] -= 1;
            }
        }
    }
}

void reset() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            visited[i][j] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    cin >> N;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> area[i][j];

            maxHeight = max(maxHeight, area[i][j]);
        }
    }

    for(int k = 0; k < maxHeight; k++) {
        int cnt = 0;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {

                // 방문했거나 잠긴 위치는 DFS를 시작하지 않음
                if(visited[i][j] || area[i][j] == 0) continue;

                // DFS를 시작했다면 안전 지역 증가
                DFS(i, j);
                cnt++;
            }
        }
        ans = max(ans, cnt);
        minusAll();
        reset();
    }

    cout << ans;
}