#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    // 우선순위큐는 디폴트로 최대힙
    priority_queue<int> pq;
    vector<int> vec;
    int N;
    cin >> N;
    
    
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        // 입력값이 자연수면 힙에 삽입
        if (num) {
            pq.push(num);
        }
        // 입력값이 0이거나 힙이 비어있을떄
        else{
            if (pq.empty())
                vec.push_back(0);
            else {
                vec.push_back(pq.top());
                pq.pop();
            }
        }
    }
    for (auto it = vec.begin(); it != vec.end(); it++)
        cout << *it << '\n';
	return 0;
}