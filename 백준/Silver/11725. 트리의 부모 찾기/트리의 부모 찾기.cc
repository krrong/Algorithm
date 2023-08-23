//https://www.acmicpc.net/problem/11725
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
vector<int> graph[100001];	// 그래프
bool visit[100001];			// 방문여부 저장
int parent[100001];			// 부모 노드값 저장

void bfs() {
	queue<int> q;
	q.push(1);
	visit[1] = true;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < graph[cur].size(); i++) {
			// 방문하지 않았으면
			if (visit[graph[cur][i]] == false) {
				visit[graph[cur][i]] = true;	// 방문표시
				parent[graph[cur][i]] = cur;	// 부모노드 저장
				q.push(graph[cur][i]);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;

		// 무향 그래프 연결
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	bfs();

	for (int i = 2; i <= n; i++) {
		cout << parent[i] << '\n';
	}


	return 0;
}