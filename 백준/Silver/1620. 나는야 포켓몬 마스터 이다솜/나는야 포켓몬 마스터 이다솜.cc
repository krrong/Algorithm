#include <iostream>
#include <string>
#include <map>
using namespace std;

int n, m;
string name;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	map<string, string> ma;

	int num = 1;
	for (int i = 0; i < n; i++) {
		cin >> name;
		ma.insert(make_pair(name, to_string(num)));
		ma.insert(make_pair(to_string(num), name));
		num++;
	}

	for (int i = 0; i < m; i++) {
		cin >> name;
		auto e = ma.find(name);
		cout << e->second << '\n';
	}
}