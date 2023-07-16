#include <iostream>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    map<string, string> pw;
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string p, name;
        cin >> p >> name;
        pw.insert({ p,name });
    }
    for (int i = 0; i < M; i++) {
        string s;
        cin >> s;
        cout << pw[s] <<'\n';
    }
    
    return 0;
}
 