# bj_1012(BFS,DFS)

[https://www.acmicpc.net/problem/1012](https://www.acmicpc.net/problem/1012)

```cpp
#include <iostream>
#include <vector>
#include<algorithm>
#include<queue>

using namespace std;

int T, M, N, K;

// 밭
vector<vector<int>> pp(51, vector<int>(51));

bool visit[51][51] = { 0, };
int bug = 0;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0, 1,0,-1 };

queue<pair<int, int>> q;

void bfs(int start_y, int start_x) {
	
	visit[start_y][start_x] = 1;
	q.push(make_pair(start_y, start_x));

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;

		q.pop();
		for (int i = 0; i < 4; i++) {
			int x_new = x + dx[i];
			int y_new = y + dy[i];

			if ((0 <= x_new && x_new < M) && (0 <= y_new && y_new < N) && !visit[y_new][x_new]
				&& pp[y_new][x_new] == 1) {

				visit[y_new][x_new] = 1;
				q.push(make_pair(y_new, x_new));
			}
		}
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> M >> N >> K;
		for (int j = 0; j < K; j++) {
			int X, Y;
			cin >> X >> Y;
			pp[Y][X] = 1;
		}
		
		// bfs로 연결요소 탐색
		for (int p = 0; p < N; p++) {
			for (int q = 0; q < M; q++) {
				if (pp[p][q] == 1 && visit[p][q] == 0) {
					bfs(p, q);
					bug++;
				}
			}
		}
		cout << bug << '\n';
		
		bug = 0;
		for (int i = 0; i < N; i++) {
			fill(visit[i], visit[i] + M, 0);
			pp[i].assign(M, 0);
		}
	}
	return 0;
}
```

딱 보고 bfs로 풀 수 있을거라고 생각. 이유는 연결요소 4(상하좌우)로 탐색해야 풀 수 있을 거라 생각했기 때문. 하지만 조금 잔실수가 있어서 푸는데 꽤 걸림.

## 풀면서 헤맸던 부분

- X와 Y의 변수의미를 확실히 안했던것.(가로를 X로 지정하고 Y로 지정하고 했어야했는데 그렇지 않고 그 반대로 함. 그로인해 헷갈리게 구현함)
- 벌레 수와 방문지점을 테스트 케이스마다 초기화를 했어야했는데 안했었음.(항상 유의)

### 시간복잡도

- 입력 → O(N^2)
- 탐색 + bfs → O(N^2) + O(N^2) - 탐색 필요성 검증 = O(N^2)
- 초기화 → O(N^2)

**총 시간 복잡도 → O(N^2)**