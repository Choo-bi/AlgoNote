# bj_1074(Divide & Conquer) -X-

[https://www.acmicpc.net/problem/1074](https://www.acmicpc.net/problem/1074)

```cpp
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
```

1시간 넘게 붙들었지만 풀 지 못한 문제..

### 내가 못 푼 이유

- 일일히 배열에 값을 계산하며 품(일단 디버깅을 하기위함)
- 16*16 배열까진 잘 됐는데 32*32부터 값이 이상하게 드간 부분을 확인했으나 해결 못함(답을 보고 나니 재귀부분에서 값을 더해주는 것을 잘못함)

일단 못풀었으니 체크해놓고 다시 풀어보도록 하자.