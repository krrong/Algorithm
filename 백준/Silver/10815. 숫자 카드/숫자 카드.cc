// 백준 10815번 : 숫자 카드 (
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> sang;
vector<int> represent;

bool binarySearch(int search) {
	int start, end, mid;
	start = 0;
	end = sang.size() - 1;

	while (start <= end) {
		mid = (start + end) / 2;

		if (sang[mid] == search) {
			return true;
		}
		else if (sang[mid] > search) {	// 찾는 값보다 중간값이 큰 경우
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		sang.push_back(a);
	}

	sort(sang.begin(), sang.end());

	cin >> M;
	for (int i = 0; i < M; i++) {
		int a;
		cin >> a;
		cout << binarySearch(a) << ' ';
	}



	return 0;
}