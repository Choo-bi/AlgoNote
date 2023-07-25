#include <iostream>
#include <vector>

using namespace std;

int N, M;

vector<int> a(9);
bool visited[9] = { false, };

void dfs(int n, int cnt) {
    if (cnt == M) {
        for (int i = 0; i < M; i++) {
            cout << a[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = n; i <= N; i++) {
        
            a[cnt] = i;
            dfs(i,cnt+1);
       
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    dfs(1, 0);

    return 0;
}