#include <iostream>
#include <vector>
using namespace std;

int N, M, Max;
vector<long> treeHeighs;

long getLength(int height) {
    long length = 0;

    for(int i = 0; i < N; i++) {
        long canGetLength = treeHeighs[i] - height;

        if(canGetLength > 0) {
            length += canGetLength;
        }
    }

    return length;
}

long binarySerach() {
    long low = 1;
    long high = Max;

    while(low <= high) {
        long mid = (low + high) / 2;

        long treeLength = getLength(mid);

        if(treeLength <= M) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    if (getLength(low) >= M) {
        return low;
    }
    return high;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;    
    
    for(int i = 0; i < N; i++) {
        long height;
        cin >> height;

        if(Max < height) {
            Max = height;
        }

        treeHeighs.push_back(height);
    }

    cout << binarySerach();

    return 0;
}