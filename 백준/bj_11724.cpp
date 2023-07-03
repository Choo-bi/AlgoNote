#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M;
    cin >> N >> M;
    // 그래프 형성
    vector<int> vec[1001];
    for (int i = 0; i < M; i++) {
        int first, second;
        cin >> first >> second;
        vec[first].push_back(second);
        vec[second].push_back(first);
    }

    queue<int> q;
    bool visited[1001] = { false, };

    // 연결요소 수
    int cnt = 0;
    for (int k = 1; k <= N; k++) {
        int start = k;
        // 방문한 곳에 미포함된 요소이면 연결요소 개수 증가
        if (!visited[k]) {
            cnt++;
        }
        else
            continue;
        // bfs로 탐색
        visited[start] = true;
        q.push(start);
        while (!q.empty()) {
            int p = q.front();
            q.pop();
            for (int i = 0; i < vec[p].size(); i++) {
                int k = vec[p][i];
                if (!visited[k]) {
                    q.push(k);
                    visited[k] = true;
                }
            }
        }
    }
    
    cout << cnt;
}