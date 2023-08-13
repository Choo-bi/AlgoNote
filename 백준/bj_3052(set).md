# bj_3052(set)

[https://www.acmicpc.net/problem/3052](https://www.acmicpc.net/problem/3052)

```cpp
#include <iostream>
#include <set>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	set<int> s;
	// 세트는 중복없이 입력이 가능
	for (int i = 0; i < 10; i++) {
		int num;
		cin >> num;
		s.insert(num % 42);
	}
	cout << s.size();

	return 0;
}
```

중복없이 입력이 가능한 세트를 활용하면 간단히 풀 수 있는 문제