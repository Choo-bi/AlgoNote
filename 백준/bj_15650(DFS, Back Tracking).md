# bh_15650(DFS, Back Tracking)

[https://www.acmicpc.net/submit/15650](https://www.acmicpc.net/submit/15650)

```cpp
#include <iostream>
#include <vector>

using namespace std;

bool selected[9] = { false, };
int a[9] = { 0, };

int N, M;

void dfs(int cnt, int idx) {
    if (cnt == M) {
        for (int i = 0; i < M; i++) {
            cout << a[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = idx; i <= N; i++) {
        if (!selected[i]) {
            selected[i] = true;
            a[cnt] = i;
            dfs(cnt + 1, i+1);
            selected[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    dfs(0,1);

    return 0;
}
```

dfs를 응용한 문제이다.  푸는데에 어려움을 겪고, 힌트를 보고 백트래킹 알고리즘이란 것을 알고나서 풀게 되었다.