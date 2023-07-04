#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

	int N;
	cin >> N;

	// 힙
	priority_queue<int> pq;
	// 출력벡터
	vector<int> v;

	// pq에 입력값 삽입
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		// 최소힙으로 구현하기위해 음수로 입력
		if (num) {
			pq.push((-1) * num);
		}
		// 큐가 비었을떄는 v에 0을 넣고 아니면 큐의 탑을 추출하여 v에 삽입.
		else {
			if (pq.empty())
				v.push_back(0);
			else {
				v.push_back((-1)*pq.top());
				pq.pop();
			}
		}
	}
	for (auto it = v.begin(); it != v.end(); it++)
		cout << *it << '\n';

	return 0;
}