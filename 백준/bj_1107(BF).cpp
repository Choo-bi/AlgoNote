#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int N, M;
bool btn[10] = { false, };

// 인자로 받은 수는 숫자버튼으로 입력가능한지 판별
bool isPossible(int num) {
	string s = to_string(num);
	for (int i = 0; i < s.size(); i++) {
		// 아스키코드 연산
		if (btn[s[i] - 48])
			return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	// 고장난 버튼 입력
	for (int i = 0; i < M; i++) {
		int bb;
		cin >> bb;
		btn[bb] = true;
	}
	// 입력이 100이면 0 출력
	if (N == 100) {
		cout << 0;
		return 0;
	}

	int ans = abs(N - 100);

	// 채널갯수는 무한개이므로 최대입력은 500000이지만, 1000000까지 탐색
	// (만약 500000을 입력하려는데 012345가 고장났을때를 대비) 
	for (int i = 0; i < 1000001; i++) {
		if (isPossible(i)) {
			// abs(N-i) : +- 누르는 횟수
			// to_string(i).size : 숫자버튼 누르는 횟수 
			int temp = abs(N - i) + to_string(i).size();
			ans = min(ans, temp);
		}
	}
	cout << ans;

	return 0;
}