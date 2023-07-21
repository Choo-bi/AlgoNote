# bj_11047(Greedy)

[https://www.acmicpc.net/problem/11047](https://www.acmicpc.net/problem/11047)

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;
    vector<int> v(N);
    
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    int cnt = 0,s = K, rem = K;
    for (int i = N - 1; i > -1; i--) {
        s = rem / v[i];
        rem %= v[i];
        cnt += s;
        if (rem == 0) break;
    }
    cout << cnt;
    return 0;
}
```

DP 인지 그리디인지 헷갈렸었지만 일단 그리디부터 해보고 안되면 DP를 고민해보자라고 생각하며 구현했다. 그러나 실버4에선 그리디를 쓸 수 있는지 볼 수준이였는지 그리디로 간단히 풀 수 있었다.

### 시간복잡도

- 입력 → O(N)
- 그리디 알고리즘 → O(N)

**총 시간복잡도 → O(N)**