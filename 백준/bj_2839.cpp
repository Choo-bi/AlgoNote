#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;
    bool flag = true;
    int w1 = 5, w2 = 3;
    // cnt1 : 5키로 봉지 수, cnt2 : 3키로
    int cnt1 = N / 5;
    int cnt2 = 0;
    while (flag) {
        // 5키로 봉지수를 최대 갯수로 잡고 0이 될때까지 반복
        for (int i = cnt1; i >= 0; i--) {
            // tmp : 5키로로 나눈 나머지
            int tmp = N - (w1 * cnt1);

            // tmp가 0이면 3키로 봉지로만 가능.
            if (!tmp) {
                flag = !flag;
                break;
            }
            // tmp가 0이 아닌 3의 배수일 때 cnt2를 계산하고 출력
            if (tmp % w2 == 0) {
                cnt2 = tmp / w2;
                flag = !flag;  
                break;
            }
            // 어느 봉지로도 다 못담을 때
            if (cnt1 == 0 && tmp % w2 != 0) {
                cout << -1;
                return 0;
            }
            cnt2++;
            cnt1--;
        }
    }
    cout << cnt2 + cnt1;
}
