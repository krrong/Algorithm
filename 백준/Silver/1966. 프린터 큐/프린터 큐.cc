#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int t, n, m, val;

bool comp(int a, int b) {
	if (a > b)return true;
	return false;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> t;

	while (t--) {
		cin >> n >> m;
		queue<pair<int, int>> docu;	// 문서 번호, 문서 중요도
		vector<int> v; // 중요도 
		int cnt = 1;
		
		int maxImportant = 0;	// 현재 큐에서 가장 큰 문서 중요도
		for (int i = 0; i < n; i++) {
			cin >> val;	// 중요도
			docu.push(make_pair(i, val));	// 문서 번호(0번부터 시작), 문서 중요도
			v.push_back(val);
			maxImportant = max(maxImportant, val);
		}

		sort(v.begin(), v.end(), comp);	// 문서 중요도 순서 내림차순 정렬

		while (true) {
			pair<int, int> tmp = docu.front();
			docu.pop();

			// 큐의 첫째 문서가 궁금한 문서라면 순서 출력
			if (tmp.first == m && tmp.second >= maxImportant) {
				cout << cnt << '\n';
				break;
			}

			// 큐의 첫째 문서의 중요도가 가장 높다면 출력
			if (tmp.second >= maxImportant) {
				cnt++;

				v.erase(v.begin());
				maxImportant = v[0];
			}
			// 큐의 첫째 문서의 중요도가 가장 높지 않으면
			else {
				docu.push(tmp);
			}
		}
	}

 }