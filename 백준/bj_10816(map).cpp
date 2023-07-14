#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    int num;
    map<int,int> n;
    // 맵에 입력값 삽입
    // 중복데이터일 경우 value 증가
    for (int i = 0; i < N; i++) {
        cin >> num;
        if (n.find(num) != n.end())
            n[num]++;
        else
            n.insert({num, 1});
    }
    int M;
    cin >> M;
    vector<int> m(M);
    for (int i = 0; i < M; i++) {
        cin >> m[i];
    }
    // 입력받은 맵에서 key를 탐색한 후 value 값 출력
    for (int i = 0; i < M; i++) {
        if (n.find(m[i]) != n.end())
            cout << n[m[i]] << ' ';
        else
            cout << 0 << ' ';
    }
    
    return 0;
}
 