#include <iostream>
#include <vector>


using namespace std;

vector<int> dp(50001);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    dp[0] = 0;
    dp[1] = 1;

    // DP
    for (int i = 2; i < 50001; i++) {
        dp[i] = dp[i - 1] + 1;
        // 1제곱부터 차례로 비교해가며 더 작은 제곱합을 탐색(부르트포스)
        for (int j = 1; j * j <= i; j++) {
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }
    cout << dp[N];
}
         