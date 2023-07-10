#include <iostream>
#include <queue>

using namespace std;

queue<pair<int, int>> q;
bool visited[100001] = { false, };

bool valid(int i) {
    if (i < 0 || i > 100000 || visited[i])
        return 0;
    else
        return 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int start, dest;
    cin >> start >> dest;

    int depth = 0;
    pair<int, int> p = { start , depth };
    q.push(p);
    visited[start] = true;
    while (!q.empty()) {
        int x = q.front().first;
        depth = q.front().second;
        q.pop();
        if (x == dest) break;
        if (valid(x - 1)) {
            q.push({ x - 1, depth + 1 });
            visited[x -1] = true;
        }
        if (valid(x + 1)) {
            q.push({ x + 1, depth + 1 });
            visited[x + 1] = true;
        }
        if (valid(2 * x)) {
            q.push({ 2 * x, depth + 1 });
            visited[2 * x] = true;
        }
    }

    cout << depth;

	return 0;
}