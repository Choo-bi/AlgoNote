# bj_7569(BFS)

[https://www.acmicpc.net/problem/7569](https://www.acmicpc.net/problem/7569)

```cpp
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;

int farm[102][102][102];

int M, N, H,days=0;

// 3차원 단위이동
int dx[6] = { 0,1,0,-1,0,0 };
int dy[6] = { 1,0,-1,0,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };

queue<tuple<int, int, int>> q;

// 3차원 너비우선탐색
void bfs() {
	while (!q.empty()) {
		int x = get<2>(q.front());
		int y = get<1>(q.front());
		int z = get<0>(q.front());
		q.pop();
		for (int i = 0; i < 6; i++) {
			int px = x + dx[i];
			int py = y + dy[i];
			int pz = z + dz[i];
			if ((px >= 1 && px <= M)
				&& (py >= 1 && py <= N)
				&& (pz >= 1 && pz <= H)
				&& (farm[pz][py][px] == 0)) {
				q.push({ pz,py,px });
				farm[pz][py][px] = farm[z][y][x] + 1;
				days = max(days, farm[pz][py][px]);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M >> N >> H;

	bool flag=false;
	// 입력
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= M; k++) {
				int tomato;
				cin >> tomato;
				farm[i][j][k] = tomato;
				// 시작점을 큐에 미리 담아서 다중 시작점 bfs를 구현
				if (tomato == 1) {
					q.push({ i,j,k });
				}
				// 이미 다 익은 농장일때를 대비한 조건
				else if (tomato == 0)
					flag = true;
			}
		}
	}

	bfs();

	// 농장을 탐색하여 적절한 답 출력
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= M; k++) {
				if (farm[i][j][k] == 0) {
					cout << -1;
					return 0;
				}
			}
		}
	}
	if (flag) cout << days - 1;
	else cout << days;

	return 0;
}
```

3차원의 BFS를 구현하는 것이 핵심이었던 문제, 또한 다중 시작점 BFS를 구현할 줄 알아야 풀 수 있었다.

### 내가 헤맨 부분

- 튜플 라이브러리를 처음 써봐서 다소 헷갈렸다.