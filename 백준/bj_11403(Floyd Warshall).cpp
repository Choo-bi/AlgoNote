#include <iostream>

using namespace std;

int n;
int matrix[101][101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	// 입력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> matrix[i][j];
		}
	}

	// 플로이드 워셜
	// 거치는 지점
	for (int k = 0; k < n; k++) {
		// 출발 지점
		for (int i = 0; i < n; i++) {
			// 도착 지점
			for (int j = 0; j < n; j++) {
				if (matrix[i][k] && matrix[k][j]) {
					matrix[i][j] = 1;
				}
			}
		}
	}

	// 출력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << matrix[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}