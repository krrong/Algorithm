#include <iostream>

using namespace std;
int N;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    bool skWin = true;
    for(int i = 1; i < N; i++) {
        if(skWin) {
            skWin = false;
        }
        else {
            skWin = true;
        }
    }

    if(skWin) {
        cout << "SK";
    }
    else {
        cout << "CY";
    }

    return 0;
}

