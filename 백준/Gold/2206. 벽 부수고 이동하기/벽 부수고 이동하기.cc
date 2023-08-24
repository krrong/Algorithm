// 백준 2206번 : 벽 부수고 이동하기 ()
#include <iostream>
#include <queue>
#include <vector>
#define INF 1e9
using namespace std;

int N, M;
int map[1001][1001];
int dist[1001][1001][2];	// x, y, 뚫을 수 있는 횟수
int answer = 0;
int dx[4] = { -1,1,0,0 };	// 상하좌우
int dy[4] = { 0,0,-1,1 };

int BFS() {
	queue<pair<pair<int, int>, int>> q;	// <<x, y>, 뚫을 수 있는 벽의 수>
	q.push({ {1, 1}, 1 });
	dist[1][1][1] = 1;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int wall = q.front().second;
		q.pop();

		if (x == N && y == M) {	// 목적지에 도착한 경우
			return dist[x][y][wall];
		}

		for (int dir = 0; dir < 4; dir++) {
			int mx = x + dx[dir];
			int my = y + dy[dir];

			if (mx < 1 || mx > N || my < 1 || my > M) continue;	// 범위를 벗어나는 경우 pass

			if (map[mx][my] == 1 && wall == 1) {	// 벽이고, 뚫을 수 있는 횟수가 있을 때
				dist[mx][my][wall - 1] = dist[x][y][wall] + 1;
				q.push({ { mx, my }, wall - 1 });
			}

			if (map[mx][my] == 0) {				// 이동할 수 있는 길이라면
				if (dist[mx][my][wall] == 0) {	// 방문하지 않았다면
					dist[mx][my][wall] = dist[x][y][wall] + 1;
					q.push({ { mx, my }, wall });
				}
			}
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		string a;
		cin >> a;
		for (int j = 0; j < M; j++) {
			map[i][j + 1] = a[j] - 48;
		}
	}

	answer = BFS();
	cout << answer;

	return 0;
}