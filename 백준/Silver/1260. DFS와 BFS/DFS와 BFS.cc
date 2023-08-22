// 백준 1260번 : DFS와 BFS (S2 17시작)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, V;
vector<int> graph[1001];
bool visited[1001];
stack<int> s;
queue<int> q;


void BFS(int start) {
	visited[start] = true;
	q.push(start);
	cout << start << ' ';

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < graph[cur].size(); i++) {
			if (visited[graph[cur][i]] == false) {
				visited[graph[cur][i]] = true;
				q.push(graph[cur][i]);
				cout << graph[cur][i] << ' ';
			}
		}
	}
}

void DFS(int start) {
	visited[start] = true;
	s.push(start);
	cout << start << ' ';

	while (!s.empty()) {
		int cur = s.top();
		s.pop();

		for (int i = 0; i < graph[cur].size(); i++) {
			if (visited[graph[cur][i]] == false) {
				visited[graph[cur][i]] = true;
				DFS(graph[cur][i]);
				//s.push(graph[cur][i]);
				//cout << graph[cur][i] << ' ';
				//break;
			}
		}
	}
}

void reset() {
	fill_n(visited, 1001, false);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> V;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 1; i <= N; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	DFS(V);
	reset();
	cout << '\n';
	BFS(V);


	return 0;
}