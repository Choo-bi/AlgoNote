#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 너비 우선 탐색
void bfs(long long start, long long end) {

	vector<bool>visited(end+1);
	queue<pair<long long, long long>> q;
	pair<long long, long long> p;
	q.push({start, 1});
	visited[start] = true;

	while (!q.empty()) {
		// 노드
		long long p = q.front().first;
		// 그래프 레벨(depth)
		int cnt = q.front().second;
		
		// end에 도달시 종료
		if (p == end) {
			cout << cnt;
			return;
		}
		q.pop();
		// 1번째 계산
		if ( p*2 <= end && !visited[p * 2]) {
			q.push({ p * 2 ,cnt+1});
			visited[p * 2] = true;
		}
		// 2번째 계산
		if ( p*10+1 <=end && !visited[p * 10 + 1]) {
			q.push({ p * 10 + 1 ,cnt+1});
			visited[p * 10 + 1] = true;
		}
	}
	cout << -1;
	
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long A, B;
	cin >> A >> B;
	
	bfs(A,B);

	return 0;
}