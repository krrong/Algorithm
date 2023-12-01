#include <iostream>
using namespace std;

int main() {
	int n;
	int divisor[5];

	for (int i = 0; i < 5; i++) {
		cin >> n;
		divisor[i] = n;
	}

	int result = 1;
	int count = 0;
	while (true) {
		for (int i = 0; i < 5; i++) {
			if (result % divisor[i] == 0) {
				count++;
			}
			if (count >= 3) {
				cout << result;
				return 0;
			}
		}
		result++;
		count = 0;
	}

}
