#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;
    vector<int> pc[101];
    int num;
    cin >> num;

    // 그래프 형성
    for (int i = 1; i <= num; i++) {
        int first = 0;
        int second = 0;
        cin >> first >> second;
        pc[first].push_back(second);
        pc[second].push_back(first);
    }


    // bfs 탐색
    bool visited[101] = { false, };
    queue<int> q;
    q.push(1);
    visited[1] = true;

    while (!q.empty()) {
        int t = q.front();
        q.pop();
        for (int i = 0; i < pc[t].size(); i++) {
            int p = pc[t][i];
            if (!visited[p]) {
                q.push(p);
                visited[p] = true;
            }
        }
    }
    // 방문한 곳이 곧 감염된 pc 수 
    int cnt=0;
    for (int i = 0; i < 101; i++) {
        if (visited[i])
            cnt++;
    }
    cout << cnt - 1;

}