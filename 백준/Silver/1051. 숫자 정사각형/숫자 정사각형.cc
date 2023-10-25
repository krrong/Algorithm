#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

int n, m;
int square[50][50];
string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 가장 작은 크기는 0이 아니라 1임
	int area = 1;
	cin >> n >> m;

	// 입력
	for (int i = 0; i < n; i++) {
		cin >> s;

		for (int j = 0; j < s.size(); j++) {
			square[i][j] = s[j] - '0';
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 1; k <= min(n, m); k++) {
				// 네 꼭짓점이 같고
				if (i + k < n && j + k < m && square[i][j] == square[i + k][j] && square[i][j] == square[i][j + k] && square[i][j] == square[i + k][j + k]) {
					// 현재 크기가 더 작다면 갱신
					if (area < (k + 1) * (k + 1)) {
						area = (k + 1) * (k + 1);
					}
				}
			}
		}
	}

	cout << area;
}