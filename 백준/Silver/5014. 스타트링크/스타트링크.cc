#include <iostream>
#include <queue>
#define MAX 1e9
using namespace std;

int F, S, G;
int upDown[2];

bool visited[1000002];
int dist[1000002];

bool valid(int floor) {
    return (floor >= 1 && floor <= F);
}

void BFS(int floor) {
    queue<int> que;
    que.push(floor);
    visited[floor] = true;
    dist[floor] = 0;

    while(!que.empty()) {
        int curFloor = que.front();
        que.pop();

        if(curFloor == G) {
            return;
        }

        for(int dir = 0; dir < 2; dir++) {
            int nextFloor = curFloor + upDown[dir];

            if(!valid(nextFloor) || visited[nextFloor]) continue;

            // 유효한 값이고, 방문하지 않은 경우
            que.push(nextFloor);
            visited[nextFloor] = true;
            dist[nextFloor] = min(dist[nextFloor], dist[curFloor] + 1);
        }
    }
}

// 최대 거리로 초기화
void setUp() {
    fill_n(dist, 1000001, MAX);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int d;
    cin >> F >> S >> G >> upDown[0] >> d;
    upDown[1] = -d;

    setUp();
    BFS(S);

    if(dist[G] == MAX) {
        cout << "use the stairs";
    }
    else {
        cout << dist[G];
    }

    return 0;
}