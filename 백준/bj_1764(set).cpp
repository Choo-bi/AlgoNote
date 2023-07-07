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