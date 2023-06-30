#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int K, N;
    cin >> K >> N;
    vector<int> lans(K);
    for (int i = 0; i < K; i++) {
        cin >> lans[i];
    }
    sort(lans.begin(), lans.end());
    long long max = lans[K - 1];
    long long min = 1;
    long long mid = 1;
    int ans = 0;
    while (min <= max) {
        int cnt = 0;
        mid = (max + min) / 2;
        for (int i = 0; i < K; i++) {
            cnt += lans[i] / mid;
        }
        if (cnt >= N) {
            min = mid + 1;
            ans = ans < mid ? mid : ans;
        }
        else {
            max = mid - 1;
 
        }
    }
    cout << ans;

}
