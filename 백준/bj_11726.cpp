#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<unsigned long long> c (1001);
    c[1] = 1;
    c[2] = 2;

    // DP 알고리즘 ( 피보나치? )
    for (int i = 3; i < 1001; i++) {
        c[i] = (c[i - 1] + c[i - 2]) % 10007;
    }

    int n;
    cin >> n;
    cout << c[n];

	return 0;
}