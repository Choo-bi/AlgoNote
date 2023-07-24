# bj_1676(Math)

[https://www.acmicpc.net/problem/1676](https://www.acmicpc.net/problem/1676)

```cpp
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;
 
    
    if (N >= 125) {
        cout << N / 5 + N / 25 + N/125;
    }
    else if (N >= 25) {
        cout << N / 5 + (N / 25);
    }
    else
        cout << N / 5;

    return 0;
}
```

5의 제곱수들로 나눈 몫의 합이 곧 0의 개수라는 것을 파악하면 풀 수 있었던 문제. 
딱히 특별한 알고리즘이 없고, 수학적 센스로 풀 수 있는 문제.