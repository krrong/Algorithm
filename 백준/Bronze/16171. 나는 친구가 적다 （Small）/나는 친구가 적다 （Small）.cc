#include <iostream>
#include <string>
#include <vector>
using namespace std;

string S;
string K;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> S >> K;

    int sSize = S.size();

    // 숫자 제거
    string removedStr = "";
    for(int i = 0; i < sSize; i++) {
        if(9 >= (S[i] - '0') && 0 <= (S[i] - '0')) continue;
        removedStr.push_back(S[i]);
    }

    if(removedStr.find(K) == string::npos) {
        cout << 0;
        return 0;
    }
    cout << 1;

    return 0;
}
