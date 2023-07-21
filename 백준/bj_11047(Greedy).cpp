#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;
    vector<int> v(N);
    
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    int cnt = 0,s = K, rem = K;
    for (int i = N - 1; i > -1; i--) {
        s = rem / v[i];
        rem %= v[i];
        cnt += s;
        if (rem == 0) break;
    }
    cout << cnt;
    return 0;
}
 