# bj_11582(Divide & Conquer)

[https://www.acmicpc.net/problem/11582](https://www.acmicpc.net/problem/11582)

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> pp(1024 * 1024);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> pp[i];
    }
    int K;
    cin >> K;
    int cnt = N;
    while (cnt != K) {
        cnt /= 2;
        for (int i = 0; i < N; i += N/cnt) {
            sort(pp.begin() + i, pp.begin() + i + N/cnt);
        }
       
    }
    for (auto it = pp.begin(); it != pp.begin() + N; it++) {
        cout << *it << ' ';
    }

    return 0;
}
```

분할 정복 연습용 문제인데 재귀가 없는 간단한 문제였음. 익덱스 슬라이싱만 잘 할줄 알다면 풀 수 있었던 간단한 문제.

### 시간복잡도

- 입력 → O(N)
- 정렬 + 반복 ( NlogN + logN) → O(NlogN)
- 출력 → O(N)

**총 시간복잡도 : O(NlogN)**