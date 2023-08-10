# bj_1629(Divide & Conquer, 거듭제곱)

[https://www.acmicpc.net/problem/1629](https://www.acmicpc.net/problem/1629)

```cpp
#include <iostream>

using namespace std;

unsigned long long A, B, C;
int sol(int cnt) {

	if (cnt == 1) 
		return A % C;

	unsigned long long ans = sol(cnt / 2) % C;

	if (cnt % 2 == 0) 
		return ans * ans % C;
	else 
		return ans * ans % C * A % C;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> A >> B >> C;
	cout << sol(B);

	return 0;
}
```

이 문제는 일반적인 방법으로 접근하면 O(N)이라는 시간복잡도를 가지게 되므로 O(logN)인 분할정복 거듭제곱법으로 해결할 수 있었다.

기본적인 분할정복 거듭제곱법에 나머지연산을 잘 적절히 하면 해결할 수 있었다.

### 내가 헤맨 부분

- 분할정복 거듭제곱법에 무지하여 메모리초과 및 시간초과가 발생함.
- 분할기점에서 mod 연산을 안했었음. (mod 연산에 아직 익숙치 않은듯하다)