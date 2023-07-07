# bj_1764(set)

[https://www.acmicpc.net/problem/1764](https://www.acmicpc.net/problem/1764)

알고리즘 : 자료구조?

```cpp
#include <iostream>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    set<string> n;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        n.insert(s);
    }
    set<string> m;
    for (int i = 0; i < M; i++) {
        string s;
        cin >> s;
        auto it = n.find(s);
        if (it != n.end())
            m.insert(s);
    }
    cout << m.size() << '\n';
    for (auto it = m.begin(); it != m.end(); it++)
        cout << *it << '\n';

	return 0;
}
```

set는 오름차순으로 트리에 저장 되는 구조이므로, 데이터를 삽입하면 자동으로 오름차순으로 정렬된다. 선언할때 set <int, greater<int>> s 형식으로 하면 내림차순으로 저장도 가능.