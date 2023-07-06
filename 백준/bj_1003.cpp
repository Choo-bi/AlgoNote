#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T;
    cin >> T;

    // 1과 0을 호출하는 횟수를 저장하는 배열 생성
    vector<pair<int,int>> fibo(41);
    pair<int, int> p;
    p.first = 1;
    p.second = 0;
    fibo[0] = p;
    p.first = 0;
    p.second = 1;
    fibo[1] = p;
    // DP
    for (int i = 2; i < 41; i++) {
        fibo[i].first = fibo[i - 1].first + fibo[i - 2].first;
        fibo[i].second = fibo[i - 1].second + fibo[i - 2].second;
    }
    for (int i = 0; i < T; i++) {
        int N;
        cin >> N;
        cout << fibo[N].first << " " << fibo[N].second << '\n';
    }

	return 0;
}