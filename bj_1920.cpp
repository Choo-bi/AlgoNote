#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N;
    int *A = new int [N];

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(A, A+N);
    cin >> M;
    int target;

    for (int i = 0; i < M; i++) {
        cin >> target;
        cout << binary_search(A, A + N, target) << "\n";
    }
}
