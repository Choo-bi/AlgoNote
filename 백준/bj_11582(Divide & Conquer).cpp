#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> pp(1024 * 1024);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> pp[i];
    }
    int K;
    cin >> K;
    int cnt = N;
    while (cnt != K) {
        cnt /= 2;
        for (int i = 0; i < N; i += N/cnt) {
            sort(pp.begin() + i, pp.begin() + i + N/cnt);
        }
       
    }
    for (auto it = pp.begin(); it != pp.begin() + N; it++) {
        cout << *it << ' ';
    }

    return 0;
}