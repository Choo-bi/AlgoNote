#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<pair<int,int>> v;
    int N;
    cin >> N;
    int h, w;
    for (int i = 0; i < N; i++) {
        cin >> w >> h;
        v.push_back({ w,h });
    }
    vector<int> s(N);
    pair<int, int> p;
    int cnt;
    
    for (int i = 0; i < N; i++) {
        p = v[i];
        cnt = 1;
        for (int j = 0; j < N; j++) {
            if ((p.first < v[j].first && p.second < v[j].second)) {
                cnt++;
            }
        }
        s[i] = cnt;
    }
    for (int i = 0; i < N; i++) {
        cout << s[i] << ' ';
    }

    return 0;
}
 