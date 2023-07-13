#include <iostream>
using namespace std;

int N, M, s, e;
int A[100005];
int prefSum[100005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for(int i=1; i<=N;i ++) {
        cin >> A[i];

        prefSum[i] = prefSum[i-1] + A[i];
    }

    cin >> M;

    for(int i=0; i<M; i++) {
        cin >> s >> e;
        cout << prefSum[e] - prefSum[s - 1] << '\n';
    }

    return 0;
}
