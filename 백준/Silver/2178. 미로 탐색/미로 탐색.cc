// 백준 2178번 : 미로 탐색 ()
#include <iostream>
#include <queue>
using namespace std;

int N, M;
bool board[102][102];
bool visit[102][102];
int cnt[102][102];
int dx[4] = {-1, 1, 0, 0};	// 상하좌우 이동
int dy[4] = {0, 0, -1, 1};	// 상하좌우 이동

// 범위 체크
bool checkRange(int x, int y){
	return !(x <1 || x>N || y<1 || y > M);
}

void BFS() {
	queue<pair<int, int>> queue;
	queue.push({ 1, 1 });
	visit[1][1] = true;
	cnt[1][1] = 1;

	while (!queue.empty()) {
		pair<int, int> tmp = queue.front();
		queue.pop();

		for (int i = 0; i < 4; i++) {
			if (visit[tmp.first + dx[i]][tmp.second + dy[i]] == 0 && board[tmp.first + dx[i]][tmp.second + dy[i]] == 1) {
				queue.push({ tmp.first + dx[i], tmp.second + dy[i] });
				visit[tmp.first + dx[i]][tmp.second + dy[i]] = true;
				cnt[tmp.first + dx[i]][tmp.second + dy[i]] = cnt[tmp.first][tmp.second] + 1;
			}
		}
	}
}

void print() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cout << cnt[i][j] << ' ';
			//cout << board[i][j] << ' ';
		}
		cout << endl;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		string str;
		cin >> str;

		for (int j = 1; j <= M; j++) {
			if (str[j - 1] == '0') {
				board[i][j] = 0;
			}
			else {
				board[i][j] = 1;
			}
		}

	}

	BFS();
	cout << cnt[N][M];

	return 0;
}