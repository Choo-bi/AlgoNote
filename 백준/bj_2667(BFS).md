# bj_2667(BFS)

[https://www.acmicpc.net/problem/2667](https://www.acmicpc.net/problem/2667)

```cpp
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int danji[27][27];
bool visited[27][27] = { false, };

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int N;

// 단지 내 집 수 배열
vector<int> homes;
// 집 수
int nums = 0;

void bfs(int s_x, int s_y) {
	queue<pair<int, int>> q;
	visited[s_x][s_y]=true;
	q.push({ s_x,s_y });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		// 집 증가
		nums++;
		q.pop();
		// 상하좌우 탐색
		for (int i = 0; i < 4; i++) {
			int px = x + dx[i];
			int py = y + dy[i];
			if (danji[px][py] && !visited[px][py]) {
				danji[px][py] = 0;
				q.push({ px,py });
				visited[px][py] = true;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	string s[25];
	for (int i = 0; i < N; i++) {
		cin >> s[i];
	}

	// 입력
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			danji[i][j] = s[i - 1][j-1] == '1' ? 1 : 0;
		}
	}
	int danjis=0;
	// 순차적으로 탐색하면서 집을 발견하면,
	// 너비우선탐색으로 주변 집을 탐색하고 집 갯수 확인 및 단지 수 증가
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (danji[i][j]) {
				nums = 0;
				bfs(i, j);
				homes.push_back(nums);
				danjis++;
			}
		}
	}
	// 단지 내 집 개수 오름차순 정렬
	sort(homes.begin(), homes.end());

	cout << danjis << '\n';
	for (auto it = homes.begin(); it != homes.end(); it++)
		cout << *it <<'\n';
	
	return 0;
}
```

너비우선 탐색알고리즘으로 단지 내 주변 집들을 탐색하여 단지 내 집 갯수를 확인 할 수 있었다.

문제를 보고 바로 BFS라고 생각되어서 딱히 헤매지 않고 푼 문제