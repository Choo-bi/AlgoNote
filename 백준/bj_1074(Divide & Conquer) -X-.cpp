#include <iostream>
#include <cmath>

using namespace std;

int N, r, c;
int ans = 0;

void sol(int x, int y, int size)
{
	// 시작지점이 찾는 위치면 바로 리턴
	if (x == r && y == c) {
		cout << ans;
		return;
	}

	// r, c가 현재 사분면에 존재한다면
	if (r >= x && r < x + size && c >= y && c < y + size) {
		// 1사분면 탐색
		sol(x, y, size / 2);

		// 2사분면 탐색
		sol(x, y + size / 2, size / 2);

		// 3사분면 탐색
		sol(x + size / 2, y, size / 2);

		// 4사분면 탐색
		sol(x + size / 2, y + size / 2, size / 2);
	}
	else {
		// r, c가 현재 사분면에 존재하지 않는다면 현재 사분면의 크기를 더한다.
		ans += size * size;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> r >> c;
	sol(0, 0, pow(2,N));

	return 0;
}