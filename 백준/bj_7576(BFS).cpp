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