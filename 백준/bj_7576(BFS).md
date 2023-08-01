# bj_7576(BFS)

[https://www.acmicpc.net/problem/7576](https://www.acmicpc.net/problem/7576)

```cpp
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int M, N;

int days = 0;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

vector<vector<int>> farm(1000, vector<int>(1000));
bool visited[1000][1000] = { false, };

queue<pair<int, int>> q;

void bfs() {
	
	pair<int, int> p;
	
	while (!q.empty()) {
		p = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int n_y = p.first + dy[i];
			int n_x = p.second + dx[i];
			if (!visited[n_y][n_x] 
				&& (n_y >= 0 && n_y < N) 
				&& (n_x >= 0 && n_x < M)
				&& (farm[n_y][n_x] == 0)) {
				farm[n_y][n_x] = farm[p.first][p.second]+1;
				if(days<  farm[n_y][n_x]) days = farm[n_y][n_x];
				q.push({n_y,n_x});
				visited[n_y][n_x] = 1;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> farm[i][j];
			if (farm[i][j] == 1) {
				q.push({ i,j });
				visited[i][j] == 1;
			}
		}
	}

	bfs();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (farm[i][j] == 0) {
				cout << -1;
				return 0;
			}
		}
	}
	if (days > 0) cout << days - 1;
	else cout << 0;

	return 0;
}
```

다중 시작점에서 BFS를 이용하여 푸는 문제였다.

### 내가 헤맷던 부분

- 다중 시작점에서 진행되도록하려면 어떻게 해야하나?
    
    먼저 큐에 집어넣고 각각의 지점에서 부모노드에 따라 걸리는 일수를 구하여 최대 일수를 구하도록 풀었다.
    

### 시간복잡도

- 입력 → O(N^2)
- bfs + 상하좌우 탐색 → O(N^2) + O(4*N)
- 농장에 안익은 토마토가 있는지 탐색 → O(N^2)

**총 시간복잡도 → O(N^2)**