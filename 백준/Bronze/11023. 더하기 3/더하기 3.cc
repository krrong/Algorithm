#include <iostream>
using namespace std;

int sum = 0;
string nums;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    getline(cin, nums);

    int dec = 1;
    int num = 0;

    for(int i = nums.size() - 1; i >= 0; i--) {
        if(nums[i] == ' ') {
            sum += num;
            num = 0;
            dec = 1;

            continue;
        }

        num += dec * (nums[i] - '0');
        dec *= 10;
    }

    cout << sum + num;

    return 0;
}