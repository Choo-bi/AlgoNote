#include <iostream>
#include <vector>

using namespace std;

vector<long long> P(101);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, T;
    cin >> N;
    P[0] = 0;
    P[1] = 1;
    P[2] = 1;
    P[3] = 1;
    P[4] = 2;
    for (int i = 5; i < 101; i++) {
        P[i] = P[i - 1] + P[i -5];
    }
    for (int i = 0; i < N; i++) {
        cin >> T;
        cout << P[T] << '\n';
    }
}
         