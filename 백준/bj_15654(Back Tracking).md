# bj_15654(Back Tracking)

[https://www.acmicpc.net/problem/15654](https://www.acmicpc.net/problem/15654)

```cpp
#include <iostream>
#include <algorithm>

using namespace std;

int N, M;

int nums[8];
int arr[8];

bool visited[8];

void dfs(int cnt) {

	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << ' ';

		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			arr[cnt] = nums[i];
			dfs(cnt + 1);
			visited[i] = false;
		}
	}
	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}
	sort(nums, nums+N);
	
	dfs(0);

	return 0;
}
```

기존 백트래킹의 응용문제이다. 정렬과 인덱싱을 살짝 바꾸면 풀수있는 문제였다.

### 내가 헤맸던 부분

- 정렬을 이상하게 해서 자꾸 0 0 0 이 나왔다. 정렬할 인덱스만 지정하면 해결할 수 있었다.