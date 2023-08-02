#include <iostream>
#include <algorithm>

using namespace std;

int N, M;

int nums[8];
int arr[8];

bool visited[8];

void dfs(int cnt) {

	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << ' ';

		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			arr[cnt] = nums[i];
			dfs(cnt + 1);
			visited[i] = false;
		}
	}
	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}
	sort(nums, nums+N);
	
	dfs(0);

	return 0;
}