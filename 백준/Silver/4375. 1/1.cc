#include <iostream>
#include <string>
// 풀이 : 브루트포스

using namespace std;
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(cin >> n) {
        long long int ones = 1;
        int digits = 1;

        while(true) {
            if(ones % n == 0) {
                cout << digits << '\n';
                break;
            }

            ones = (ones * 10 + 1) % n;
            digits++;
        }
    }
    return 0;
}

