#include <iostream>
#include <algorithm>

using namespace std;

int T;
vector<int> v(10);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    while(T--) {
        for(int i = 0; i < 10; i++) {
            cin >> v[i];
        }

        sort(v.begin(), v.end());

        cout << v[7] << '\n';
    }

    return 0;
}

