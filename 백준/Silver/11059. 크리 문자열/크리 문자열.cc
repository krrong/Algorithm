#include <iostream>
using namespace std;

string S;

int getSum(int start, int end) {
    int sum = 0;
    for(int i = start; i <= end; i++) {
        sum += S[i] - 48;
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> S;
    int windowSize = S.size();
    int maxWindowSize = S.size();

    // 전체 길이가 홀수인 경우 짝수 윈도우로 변경
    if(maxWindowSize % 2 != 0) {
        windowSize -= 1;
    }


    // 윈도우의 크기가 1 이상인 경우
    while(windowSize > 1) {
        // 왼쪽 윈도우와 오른쪽 윈도우의 합 비교
        for(int i = 0; i <= maxWindowSize - windowSize; i++) {
            int leftHalf = getSum(i, (i + (windowSize / 2) - 1));
            int rightHalf = getSum(i + (windowSize / 2), i + (windowSize - 1));

            if(leftHalf == rightHalf) {
                cout << windowSize;
                return 0;
            }
        }

        // 윈도우 크기 축소
        windowSize -= 2;
    }

    cout << windowSize;

    return 0;
}