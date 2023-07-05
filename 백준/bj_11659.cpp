#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    // 입력 수 배열
    vector<int> vec;
    // 누적합 벡터
    vector<long> sumArr;
    sumArr.push_back(0);
    long sum = 0;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        sum += num;
        vec.push_back(num);
        sumArr.push_back(sum);
    }

    vector<int> ans;
    // 합을 구할 구간을 입력받기
    for (int i = 0; i < M; i++) {
        int start,end;
        cin >> start >> end;
        //  누적합 벡터를 활용하여 구간 합 구하기
        sum = sumArr[end] - sumArr[start-1];
        ans.push_back(sum);
    }
    for (auto it = ans.begin(); it != ans.end(); it++)
        cout << *it << '\n';

	return 0;
}