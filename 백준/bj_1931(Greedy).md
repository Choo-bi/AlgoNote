# bj_1931(Greedy)

[https://www.acmicpc.net/problem/1931](https://www.acmicpc.net/problem/1931)

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<pair<int, int>> task(N);
	
	// 빠른 종료시간 우선으로 하기위해 반대로 넣기
	for (int i = 0; i < N; i++) {
		cin >> task[i].second >> task[i].first;
	}

	sort(task.begin(), task.end());

	int time = task[0].first;
	int cnt = 1;
	for (int i = 1; i < N; i++) {
		if (time <= task[i].second) {
			cnt++;
			time = task[i].first;
		}
	}
	cout << cnt;
	
	

	return 0;
}
```

문제를 보면 바로 그리디로 접근해야겠다는 것을 알 수 있었다. 빠른 시작우선 보다는, 빠른 종료 시간우선으로 접근해야 회의를 가장 많이 받아서 할 수 있을 거라 판단.

### 내가 헤맸던 부분

- 알고리즘 접근 미숙
    
    처음에 무작정 빠른 시작시간 우선 방법으로 접근했다가 이 방법은 회의실을 가장 적고 회의실당 가장 적게 회의를 배정하는 방법이란 것을 깨달았다. 이 부분에서 가장 많이 헤맸던 것 같다.
    
- 최적화
    
    무작정 벡터를 만들어 회의실을 배정하고 회의실을 모두 탐색하며 가장 사이즈가 큰 회의실을 출력하는 방법을 취했다가 시간초과가 났다. 이 방법도 맞긴하지만 시간초과를 위해 최적화할 필요가 있었다.
    

### 시간복잡도

- 입력 → O(N)
- 정렬 → O(NlogN)
- 그리디 → O(N)

**총 시간복잡도 → O(NlogN)**