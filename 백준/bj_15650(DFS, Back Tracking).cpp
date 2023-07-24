#include <iostream>
#include <vector>

using namespace std;

bool selected[9] = { false, };
int a[9] = { 0, };

int N, M;

void dfs(int cnt, int idx) {
    if (cnt == M) {
        for (int i = 0; i < M; i++) {
            cout << a[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = idx; i <= N; i++) {
        if (!selected[i]) {
            selected[i] = true;
            a[cnt] = i;
            dfs(cnt + 1, i+1);
            selected[i] = false;
        }
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    dfs(0,1);

    return 0;
}