# bj_15652(DFS,Back Tracking)

[https://www.acmicpc.net/problem/15652](https://www.acmicpc.net/problem/15652)

```cpp
#include <iostream>
#include <vector>

using namespace std;

int N, M;

vector<int> a(9);
bool visited[9] = { false, };

void dfs(int n, int cnt) {
    if (cnt == M) {
        for (int i = 0; i < M; i++) {
            cout << a[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = n; i <= N; i++) {
        
            a[cnt] = i;
            dfs(i,cnt+1);
       
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    dfs(1, 0);

    return 0;
}
```

전에 풀었던 문제를 살짝 변형시킨 문제이다.

하지만, 굉장히 헤매서 푸는데 시간이 많이 걸렸다… 그림을 그리면서 개념을 단단히 잡고 넘어가자..