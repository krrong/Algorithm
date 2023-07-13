#include <iostream>
using namespace std;

int N, day, cnt;
int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> day;

    if(N % 4 == 0) {
        if(N % 100 != 0) {
            days[2] = 29;
        }
        else if(N % 400 == 0) {
            days[2] = 29;
        }
    }

    for(int i=1; i<=12; i++) {
        cnt += days[i] % 7;
    }

    cout << cnt;

    return 0;
}