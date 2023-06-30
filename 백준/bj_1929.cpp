#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int M, N;
    cin >> M >> N;
    vector<int> a(N+1);
    // N까지의 수 중에서 소수만 거르기 (아리스토테네스의 체 사용)
    for (int i = 2; i <= N; i++) {
        a[i] = i;
    }
    for (int i = 2; i <= N; i++) {
        if (a[i] == 0) continue;

        for (int j = 2*i; j <= N; j += i) {
            a[j] = 0;
        }
    }

    for (int i = M; i <= N; i++) {
        if (a[i] != 0)
            cout << a[i] << "\n";
    }
}

