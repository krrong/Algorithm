#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

int N, res;
vector<int> martosica;
vector<int> numberCount;

bool comp(int a, int b) {
    if (a > b) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;

        martosica.push_back(tmp);
    }

    sort(martosica.begin(), martosica.end(), comp);

    int cnt = 0;
    int curNumber = martosica[0];
    for(int i = 0; i < N; i++) {
        if(curNumber != martosica[i]) {
            numberCount.push_back(cnt); // 개수 추가
            curNumber = martosica[i];   // 현재 바라보고 있는 숫자 갱신
            cnt = 1;    // 개수 갱신
            continue;
        }
        cnt++;
    }
    numberCount.push_back(cnt); // 개수 추가

    sort(numberCount.begin(), numberCount.end(), comp);
    cout << numberCount[0];


    return 0;
}