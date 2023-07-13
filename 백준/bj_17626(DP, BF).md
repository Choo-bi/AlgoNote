# bj_17626(DP, BF)

[https://www.acmicpc.net/problem/17626](https://www.acmicpc.net/problem/17626)

```cpp
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
```

i 보다 작은 수도 모두 4개이하의 제곱수 합으로 이루어져 있으므로, DP 알고리즘을 활용하기 적절.

1부터 제곱근 i 까지 순회하면서 최소 제곱수 합 갯수 탐색 만약 i = 25일 때는 dp[0] + 1 즉 5의 제곱으로 표현할 수 있다. 

DP는 접했을땐 굉장히 어렵게 느껴지는데 풀고나면 쉽게 느껴지는 참 어려운 알고리즘..