// 백준 2217번 : 로프(S5)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int rope;
int result = 0;
vector<int> ropes;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	while (N--) {
		cin >> rope;

		// 하나의 로프를 사용하여 들어올릴 수 있는 최대 무게
		if (result < rope) {
			result = rope;
		}
		ropes.push_back(rope);
	}

	// 정렬
	sort(ropes.begin(), ropes.end());

	int cnt = 1;
	int size = ropes.size() - 1;

	while (size - cnt >= 0) {
		int tmp = ropes[size - cnt] * (cnt + 1);
		if (tmp > result) {
			result = tmp;
		}

		cnt++;
	}

	cout << result;

	return 0;
}