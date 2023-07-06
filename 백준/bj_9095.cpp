#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T;
    cin >> T;
    vector<int> v(11);
    v[1] = 1;
    v[2] = 2;
    v[3] = 4;

    for (int i = 4; i < 11; i++) {
        for (int j = 1; j <= 3; j++) {
            v[i] = v[i - 1] + v[i - 2] + v[i - 3];
        }
    }
    for (int i = 0; i < T; i++) {
        int n;
        cin >> n;
        cout << v[n] << '\n';
    }


	return 0;
}