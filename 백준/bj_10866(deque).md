# bj_10866(deque)

[https://www.acmicpc.net/problem/10866](https://www.acmicpc.net/problem/10866)

```cpp
#include <iostream>
#include <deque>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    deque<int> d;
    string s;
    for (int i = 0; i < N; i++) {
        cin >> s;
        if (s == "push_back") {
            int p;
            cin >> p;
            d.push_back(p);
        }
        else if (s == "push_front") {
            int p;
            cin >> p;
            d.push_front(p);
        }
        else if (s == "front") {
            if (!d.empty())
                cout << d.front() << '\n';
            else
                cout << -1 << '\n';
        }
        else if (s == "back") {
            if (!d.empty())
                cout << d.back() << '\n';
            else
                cout << -1 << '\n';
        }
        else if (s == "size") {
            cout << d.size() << '\n';
        }
        else if (s == "pop_front") {
            if (!d.empty()) {
                cout << d.front() << '\n';
                d.pop_front();
            }
            else
                cout << -1 << '\n';
            
        }
        else if (s == "pop_back") {
            if (!d.empty()) {
                cout << d.back() << '\n';
                d.pop_back();
            }
            else
                cout << -1 << '\n';
        }
        else if (s == "empty") {
            if (!d.empty())
                cout << 0 << '\n';
            else
                cout << 1 << '\n';
        }
    }
    return 0;
}
```

deque의 개념을 찾아보고 공부할 수 있는 기회가 되는 문제였다.