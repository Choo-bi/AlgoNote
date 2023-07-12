#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 그래프
vector<int> vec[1001];
// dfs, bfs 방문체크
bool visit[1001] = { false, };
bool _visit[1001] = { false, };

// 깊이 우선 탐색
void dfs(int start, vector<int> graph[], bool visit[]) {
    visit[start] = true;
    cout << start << ' ';
    for (int i = 0; i < graph[start].size(); i++) {
        int next = graph[start][i];
        if (!visit[next]) {
            dfs(next, graph, visit);
        }
    }
}


// 너비 우선 탐색
void bfs(int start, vector<int> graph[], bool visit[]) {
    queue<int> q;
    visit[start] = true;
    q.push(start);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        cout << x << ' ';
        for (int i = 0; i < graph[x].size(); i++) {
            int y = graph[x][i];
            if (!_visit[y]) {
                q.push(y);
                _visit[y] = true;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M, start;
    cin >> N >> M >> start;

    // 순차적으로 탐색하기 위해 정렬
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
        sort(vec[a].begin(), vec[a].end());
        sort(vec[b].begin(), vec[b].end());
    }
    
    dfs(start, vec, visit);
    cout << '\n';
    bfs(start, vec, _visit);
	return 0;
}          