#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;

vector<int> aaa[100001];
bool visited[100001];

int ans[100001];


// 너비 우선 탐색
void bfs() {

	// 루트 노드가 1로 시작
	visited[1] = true;
	queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int p = q.front();
		q.pop();

		// 자식 노드 검사
		for (int i = 0; i < aaa[p].size(); i++) {
			int c = aaa[p][i];
			if (!visited[c]) {
				ans[c] = p;
				visited[c] = true;
				q.push(c);
			}
		}
	}
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	vector<int> v;
	int start = 1;

	// 그래프 생성
	for (int i = 0; i < N-1; i++) {
		int first, second;
		cin >> first >> second;
		aaa[first].push_back(second);
		aaa[second].push_back(first);
	}
	bfs();
	for (int i = 2; i <= N; i++) {
		cout << ans[i] << '\n';
	}

	return 0;
}