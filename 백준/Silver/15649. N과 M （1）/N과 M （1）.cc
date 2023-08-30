#include <iostream>
using namespace std;

int N, M;
int arr[10];
bool visit[10];

void backtrack(int k) {
	if (k == M) {
		for (int i = 0; i < k; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (visit[i] == false) {
			visit[i] = true;
			arr[k] = i;
			backtrack(k + 1);
			visit[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	backtrack(0);

	return 0;
}