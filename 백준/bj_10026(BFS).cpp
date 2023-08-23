#include <iostream>
#include <queue>

using namespace std;

int N;

// pp1 : 정상, pp2 : 색약
int pp1[102][102];
int pp2[102][102];
bool visited1[102][102] = { false, };
bool visited2[102][102] = { false, };

int dx[4] = { 0, 1, 0,-1 };
int dy[4] = { 1, 0, -1, 0 };

int ans1=0, ans2 = 0;

// 정상
void bfs1(int sx, int sy) {
	
	queue<pair<int, int>>q;
	q.push({ sx, sy });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int px = x + dx[i];
			int py = y + dy[i];
			if (!visited1[px][py] && (pp1[x][y] == pp1[px][py])) {
				q.push({ px,py });
				visited1[px][py] = true;
			}
		}
	}
}
// 색약
void bfs2(int sx, int sy) {

	queue<pair<int, int>>q;
	q.push({ sx, sy });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int px = x + dx[i];
			int py = y + dy[i];
			if (!visited2[px][py] && pp2[x][y] == pp2[px][py]) {
				q.push({ px,py });
				visited2[px][py] = true;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	string s[100];
	for (int i = 0; i < N; i++) {
		cin >> s[i];
	}
	// 입력(R:1, G:2, B:3)
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (s[i - 1][j - 1] == 'R') {
				pp1[i][j] = 1;
				pp2[i][j] = 1;
			}

			else if (s[i - 1][j - 1] == 'G') {
				pp1[i][j] = 2;
				pp2[i][j] = 1;
			}
			else if (s[i - 1][j - 1] == 'B') {
				pp1[i][j] = 3;
				pp2[i][j] = 3;
			}
		}
	}

	// 각각의 배열에서 BFS를 통해 영역 수 확인
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (!visited1[i][j]) {
				bfs1(i, j);
				ans1++;
			}
			if (!visited2[i][j]) {
				bfs2(i, j);
				ans2++;
			}
		}
	}

	cout << ans1 << ' ' << ans2;
	
	return 0;
}