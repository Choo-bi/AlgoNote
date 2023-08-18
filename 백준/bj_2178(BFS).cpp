#include <iostream>
#include <queue>

using namespace std;

int maze[102][102];
bool visited[102][102] = { false, };

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int N, M;

// 너비우선탐색으로 미로 탐색
void bfs() {
	queue<pair<int,int>> q;
	q.push({ 1,1 });
	visited[1][1] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int px = x + dx[i];
			int py = y + dy[i];
			if (!visited[px][py] && maze[px][py]) {
				q.push({ px,py });
				// 움직인 거리를 저장하며 탐색
				maze[px][py] = maze[x][y] + 1;
				visited[px][py] = true;
			}
		}
		
	}
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string mm[102];
	cin >> N >> M;

	// 붙어서 입력받으므로 분리시키기
	for (int i = 1; i <= N; i++) {
		cin >> mm[i];
	}

	// 입력받은 문자가 1이면 숫자 1로 입력 아니면 0
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			maze[i][j] = mm[i][j - 1] == '1' ? 1 : 0;
		}
	}
	bfs();
	cout << maze[N][M];
	
	return 0;
}
