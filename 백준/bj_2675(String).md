# bj_2675(String)

[https://www.acmicpc.net/problem/2675](https://www.acmicpc.net/problem/2675)

```cpp
#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, R;
	cin >> T;
	string S;
	for (int i = 0; i < T; i++) {
		cin >> R >> S;
		for (int j = 0; j < S.length(); j++) {
			for (int k = 0; k < R; k++) {
				cout << S[j];
			}
		}
		cout << '\n';
	}
	
	return 0;
}
```

오늘은 일요일이라 class 1만 여러 개 풀면서 쉬어가는 날..

역시 브론즈 답게 매우 쉽게 풀 수 있었다.

### 시간복잡도

- 입력 → O(N)
- 문자열 길이 반복횟수 * 문자열길이 = O(N^2)

**총 시간복잡도 = O(N^2)**