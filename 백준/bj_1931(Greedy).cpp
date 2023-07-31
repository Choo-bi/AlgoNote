#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<pair<int, int>> task(N);
	
	// 빠른 종료시간 우선으로 하기위해 반대로 넣기
	for (int i = 0; i < N; i++) {
		cin >> task[i].second >> task[i].first;
	}

	sort(task.begin(), task.end());

	int time = task[0].first;
	int cnt = 1;
	for (int i = 1; i < N; i++) {
		if (time <= task[i].second) {
			cnt++;
			time = task[i].first;
		}
	}
	cout << cnt;
	
	

	return 0;
}