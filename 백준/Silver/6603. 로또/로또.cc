#include <iostream>
#include <vector>
using namespace std;

vector<int> nums;
vector<int> ans;
int k;

// go
// idx : 넣을 예정이 인덱스
// size : 내가 만들고 있는 ans의 사이즈
void go(int idx, int size) {
    if(size == 6) {
        for(int i = 0; i < 6; i++) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return;
    }
    
    for(int i = idx; i < k; i++) {
        ans.push_back(nums[i]);
        go(i + 1, size + 1);
        ans.pop_back();
    }
}

void reset() {
    nums.clear();
    ans.clear();
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(true) {
        cin >> k;
        if(k == 0) break;
        for(int i = 0; i < k; i++) {
            int n;
            cin >> n;
            nums.push_back(n);
        }

        go(0, 0);
        reset();
    }

    return 0;
}