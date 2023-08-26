#include <iostream>

using namespace std;

int num;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> num;

	// 브루트포스
	for (int i = 1; i < num; i++) {
		int tmp = i;
		int sum = i;

		while (tmp != 0) {
			sum += tmp % 10; // 1의 자리 더하기
			tmp /= 10;
		}

		if (sum == num) {
			cout << i << '\n';
			return 0;
		}
	}
	// 반복문이 끝나면 생성자를 못찾은 거
	cout << 0 << '\n';

	return 0;
}