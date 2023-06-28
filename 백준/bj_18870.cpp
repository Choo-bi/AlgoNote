#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<int> ans = {};
    vector<int> tmp = v;

    // 주어진 배열을 오름차순으로 정렬(중복되는 원소 제거)
    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());

    // 중복제거된 배열에서 v에서 각 원소의 상대적 크기를 알 수 있음
    // 정렬된 배열에서 lower_bound를 쓰면 좀더 효율적이다.(정렬안되면 이상한 값 나옴) 
    for (const auto& element : v) {
        auto it = lower_bound(tmp.begin(), tmp.end(), element);
        ans.push_back(distance(tmp.begin(), it));
    }

    for (const auto& element : ans) {
        cout << element << " ";
    }

    return 0;
}
