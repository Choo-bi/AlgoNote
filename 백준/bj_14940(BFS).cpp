#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;

vector<vector<int>> Map(1001, vector<int>(1001));
bool visited[1001][1001] = { 0, };

int dx[4] = { 0,1,0, -1 };
int dy[4] = { 1,0, -1,0 };

queue<pair<int, int>> q;

void bfs(int start_y, int start_x) {

	visited[start_y][start_x] = 1;
	q.push({ start_y, start_x });
	Map[start_y][start_x] = 0;

	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int x_new = cur.second + dx[i];
			int y_new = cur.first + dy[i];

			if (x_new < 0 || x_new >= m || y_new < 0 || y_new >= n) continue;
			if (visited[y_new][x_new] || Map[y_new][x_new] == 0) continue;
			visited[y_new][x_new] = 1;
			// 부모 노드로부터 영향을 받도록 한다
			Map[y_new][x_new] = Map[cur.first][cur.second]+1;
			q.push({ y_new, x_new });
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	int start_x, start_y;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> Map[i][j];
			if (Map[i][j] == 2) {
				start_x = j;
				start_y = i;
			}
		}
	}
	bfs(start_y, start_x);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			// 방문하지 못하는 지점을 -1로 표기해야함(원래 못가는 지점은 제외)
			if (visited[i][j] == 0 && Map[i][j])
				cout << -1 << ' ';
			else
				cout << Map[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}