# bj_1697(BFS)

[https://www.acmicpc.net/problem/1697](https://www.acmicpc.net/problem/1697)

```cpp
#include <iostream>
#include <queue>

using namespace std;

// 스택오버플로우를 방지하기위해 전역에 선언
queue<pair<int, int>> q;
bool visited[100001] = { false, };

// 탐색할 곳이 유효한지 검사하는 메소드
bool valid(int i) {
		// 탐색할 곳이 인덱스를 벗어나거나 방문한 곳인지 확인
    if (i < 0 || i > 100000 || visited[i])
        return 0;
    else
        return 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int start, dest;
    cin >> start >> dest;
		
		// 걸리는 시간이 곧 depth
    int depth = 0;
    pair<int, int> p = { start , depth };
    q.push(p);
    visited[start] = true;
		// bfs 알고리즘 활용
    while (!q.empty()) {
        int x = q.front().first;
        depth = q.front().second;
        q.pop();
        if (x == dest) break;
        if (valid(x - 1)) {
            q.push({ x - 1, depth + 1 });
            visited[x -1] = true;
        }
        if (valid(x + 1)) {
            q.push({ x + 1, depth + 1 });
            visited[x + 1] = true;
        }
        if (valid(2 * x)) {
            q.push({ 2 * x, depth + 1 });
            visited[2 * x] = true;
        }
    }

    cout << depth;

	return 0;
}
```

bfs를 응용하는 문제였다. 시간이 꽤나 많이 걸렸던 문제. bfs의 큐를 적절히 활용할 줄 알면 빨리 끝났을 것 같다. 
그리고 메인에 모든 데이터를 저장했을 때 오버플로가 발생했었다. 데이터를 대량으로 저장할 자료형은 전역으로 선언해야 오버플로로 부터 안전하다.