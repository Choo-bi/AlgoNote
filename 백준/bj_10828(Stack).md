# bj_10828(Stack)

[https://www.acmicpc.net/problem/10828](https://www.acmicpc.net/problem/10828)

```cpp
#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    
    stack<int> st;

    string s;
    int input = 0;

    for (int i = 0; i < N; i++) {
        cin >> s;
        if (s == "push") {
            cin >> input;
            st.push(input);
        }
        else if (s == "pop") {
            if (!st.empty()) {
                cout << st.top() << '\n';
                st.pop();
            }
            else
                cout << -1 << '\n';
        }
        else if (s == "size") {
            cout << st.size() << '\n';
        }
        else if (s == "empty")
            cout << st.empty() << '\n';
        else if (s == "top") {
            if (!st.empty())
                cout << st.top() << '\n';
            else
                cout << -1 << '\n';
        }
            
    }
}
```

스택에 멤버함수를 공부할 수 있는 문제였다.