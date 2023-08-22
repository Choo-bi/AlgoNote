#include <iostream>
#include <queue>

using namespace std;

int campus[602][602];
bool visited[602][602] = { false, };

int dx[4] = { 0,1,-1,0 };
int dy[4] = { 1,0, 0,-1 };

int N, M;

queue<pair<int, int>> q;

int ans = 0;

void bfs() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		// 상하좌우 탐색하기
		for (int i = 0; i < 4; i++) {
			int px = x + dx[i];
			int py = y + dy[i];
			if ((!visited[px][py] && campus[px][py] != -1)
				&& (px >= 1 && px <= N)
				&& (py >= 1 && py <= M)) {
				// P인 지점을 찾으면 친구 수 증가
				if (campus[px][py] == 1) ans++;
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

	cin >> N >> M;
	
	// 공백없이 입력받으므로 문자열배열로 입력받기
	string s[600];
	for (int i = 0; i < N; i++) {
		cin >> s[i];
	}

	// P : 1표기, I : 시작점으로 잡기, O : 0으로 표기, X : -1로 표기
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			int a = s[i - 1][j - 1];
			if (a == 'I') {
				q.push({ i,j });
				visited[i][j] = true;
				a = 0;
			}
			else if (a == 'O') a = 0;
			else if (a == 'X') a = -1;
			else if (a == 'P') a = 1;
			campus[i][j] = a;
		}
	}

	// 너비우선탐색
	bfs();

	if (ans)
		cout << ans;
	else
		cout << "TT";
	
	return 0;
}