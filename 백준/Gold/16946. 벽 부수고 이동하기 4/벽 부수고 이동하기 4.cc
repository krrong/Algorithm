#include <iostream>
#include <queue>
#include <map>
#include <set>
using namespace std;

int N, M, key = 0;
int board[1002][1002];
int answer[1002][1002];
int tmpCnt[1002][1002];
int keyMap[1002][1002];
bool visited[1002][1002];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
map<int, int> zeroBundles;    // 번호, 개수 저장

bool valid(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < M);
}

void BFS(int x, int y) {
    key++;
    int cnt = 0;
    queue<pair<int, int>> que;
    que.push(make_pair(x, y));
    keyMap[x][y] = key;

    while(!que.empty()) {
        int cx = que.front().first;
        int cy = que.front().second;
        que.pop();

        // 이동할 수 있는 칸의 개수 증가
        cnt++;

        for(int dir = 0; dir < 4; dir++) {
            int mx = cx + dx[dir];
            int my = cy + dy[dir];

            // 유효하지 않은 곳이면 패스
            if(!valid(mx, my)) continue;

            // 키 값이 0이 아닌경우 연결된 것을 확인했으므로 패스
            if(keyMap[mx][my] != 0) continue;

            // 이동할 수 있는 곳인 경우
            if(board[mx][my] == 0) {
                keyMap[mx][my] = key;
                que.push(make_pair(mx, my));
            }
        }
    }

    zeroBundles.insert({key, cnt});
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        string tmp;
        cin >> tmp;

        for(int j = 0; j < M; j++) {
            board[i][j] = tmp[j] - '0';
        }
    }

    // 0을 만나면 BFS를 돌려서 연결된 개수를 map에 저장
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(board[i][j] == 0 && keyMap[i][j] == 0) {
                BFS(i, j);
            }
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            // 1인 경우 상하좌우 확인
            if(board[i][j] == 1) {
                set<int> keySet;
                for(int dir = 0; dir < 4; dir++) {
                    int mx = i + dx[dir];
                    int my = j + dy[dir];

                    // 유효한 위치가 아니라면 패스
                    if(!valid(mx, my)) continue;

                    // 근처 위치의 키 값 저장
                    keySet.insert(keyMap[mx][my]);
                }

                int printCnt = 0;
                for(auto key: keySet) {
                    printCnt += zeroBundles[key];
                }
                cout << (printCnt + 1) % 10;
            }
            else {
                cout << 0;
            }
        }
        cout << '\n';
    }

    return 0;
}