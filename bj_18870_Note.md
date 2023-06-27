# 18870

백준 18870번 <좌표 압축>
[https://www.acmicpc.net/problem/18870](https://www.acmicpc.net/problem/18870)

다음과 같은 코드로 문제 접근방식을 파악하는 것은 오래걸리지 않았다.

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> v(n);
	
	for (int i = 0; i < n; i++) {
	    cin >> v[i];
	}
	
	vector<int> ans = {};
	vector<int> tmp = v;
	
	// 주어진 배열을 오름차순으로 정렬(중복되는 원소 제거)
	sort(tmp.begin(), tmp.end());
	tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
	
	// 중복제거된 배열에서 v에서 각 원소의 상대적 크기를 알 수 있음
	for (auto iter = v.begin(); iter != v.end(); iter++) {
	    auto it = find(tmp.begin(), tmp.end(), *iter);
	    ans.push_back(distance(tmp.begin(), it));
	}
	
	for (auto iter = ans.begin(); iter != ans.end(); iter++) {
	    cout << *iter << " ";
	}
	
	return 0;

}
```

하지만 위 코드를 제출한 결과 시간초과가 발생함.  최적화가 필요하다
최적화하는데에 1시간 정도 걸림.
29번째 줄 코드 에서

```cpp
for (auto iter = v.begin(); iter != v.end(); iter++) {
auto it = find(tmp.begin(), tmp.end(), *iter);
ans.push_back(distance(tmp.begin(), it));
}
```

이 부분을 lower_bound를 활용하여 다음과 같이 고치니 해결!

```cpp
for (const auto& element : v) {
auto it = lower_bound(tmp.begin(), tmp.end(), element);
ans.push_back(distance(tmp.begin(), it));
}
```

lower_bound는 정렬된 배열에서 이진탐색으로 효율적으로 find를 할 수 있다.
하지만 정렬된 배열에서만 가능!