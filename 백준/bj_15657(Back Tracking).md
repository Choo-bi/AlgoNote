# bj_15657(Back Tracking)

[https://www.acmicpc.net/problem/15657](https://www.acmicpc.net/problem/15657)

```cpp
#include <iostream>
#include <algorithm>

using namespace std;

int N, M;

int nums[8];
int arr[8];

void dfs(int cnt,int num) {

	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << ' ';

		}
		cout << '\n';
		return;
	}

	for (int i = num; i < N; i++) {
			arr[cnt] = nums[i];
			dfs(cnt + 1,i);	
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
	
	dfs(0,0);

	return 0;
}
```

기존 15652번과 굉장히 흡사한 문제였다 차이는 비순차 수열인것. 나머진 거의 같다. 그래서 딱히 헤맨 부분은 없었던 문제였다.