#include <iostream>
#include <vector>

using namespace std;

vector<int> st(301);


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> st[i];
    }
    vector<int> s(301);
    s[0] = st[0];
    s[1] = st[0]+st[1];
    s[2] = max(st[2] + st[1], st[2] + s[0]);

    // 점화식 (초기식을 그대로 가져가자)
    for (int i = 3; i < N; i++) {
        s[i] = max(st[i]+s[i-2],st[i]+st[i-1]+s[i-3]);
    }
    cout << s[N-1];
	return 0;
}          