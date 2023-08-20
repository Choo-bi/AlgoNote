#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;

vector<int> ff[101];
bool visited[101] = { false, };

int bfs(int start,int dest) {
	queue<pair<int,int>> q;
	q.push({ start ,0});
	visited[start] = true;
	while (!q.empty()) {
		// p1 : 사람 번호, p2 : 케빈 베이컨
		int p1 = q.front().first;
		int p2 = q.front().second;
		q.pop();
		for (int i = 0; i < ff[p1].size(); i++) {
			// 찾는 사람을 찾게되면 케빈 베이컨 리턴
			if (ff[p1][i] == dest) return p2+1;
			else {
				if (!visited[ff[p1][i]]) {
					q.push({ ff[p1][i],p2+1});
					visited[ff[p1][i]] = true;
				}
			}
		}
	}
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		ff[A].push_back(B);
		ff[B].push_back(A);
	}

	vector<int>kevin(N);

	// BFS로 각 사람의 케빈 베이컨 수 확인
	for (int i = 1; i <= N; i++) {
		int bacon = 0;
		for (int j = 1; j <= N; j++) {
			// 같은 번호를 갖는 경우 제외
			if (i == j) continue;
			else {
				bacon += bfs(i, j);
			}
			for (int k = 0; k < 101; k++)
				visited[k] = false;
		}
		kevin[i-1]=bacon;
	}
	// 각 사람의 케빈베이컨이 담긴 벡터에서 최소값 인덱스 출력
	cout << min_element(kevin.begin(), kevin.end()) - kevin.begin() + 1;

	return 0;
}
