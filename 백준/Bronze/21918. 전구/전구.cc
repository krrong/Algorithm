#include <iostream>
#include <vector>
#define ON 1
#define OFF 0
using namespace std;

int N, M;
vector<int> lights;

void toggle1(int index, int state) {
    lights[index] = state;
}

void toggle2(int start, int end) {
    for(int i = start; i <= end; i++) {
        if(lights[i] == ON) {
            lights[i] = OFF;
        }
        else {
            lights[i] = ON;
        }
    }
}

void toggle3(int start, int end) {
    for(int i = start; i <= end; i++) {
        lights[i] = OFF;
    }
}

void toggle4(int start, int end) {
    for(int i = start; i <= end; i++) {
        lights[i] = ON;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    lights.push_back(0);
    for(int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        lights.push_back(tmp);
    }

    for(int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        if(a == 1) {
            toggle1(b, c);
        }
        else if(a == 2) {
            toggle2(b, c);
        }
        else if(a == 3) {
            toggle3(b, c);
        }
        else if(a == 4) {
            toggle4(b, c);
        }
    }

    for(int i = 1; i <= N; i++) {
        cout << lights[i] << ' ';
    }

    return 0;
}

