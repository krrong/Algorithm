#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int n, k;
int visit[100002];

int main() {

	cin >> n >> k;

	for (int i = 0; i < 100002; ++i)
		visit[i] = -1;

	queue<int> q;
	visit[n] = 0;
	q.push(n);

	while (visit[k]==-1)
	{
		int cur = q.front();
		q.pop();

		for (int nxt : {cur - 1, cur + 1, 2 * cur})
		{
			if (nxt < 0 || nxt>100002) continue;
			if (visit[nxt]!= -1)continue;
			visit[nxt] = visit[cur] + 1;
			q.push(nxt);
		}
	}
	cout << visit[k];
	return 0;
}