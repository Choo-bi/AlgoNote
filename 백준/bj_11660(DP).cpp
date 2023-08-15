#include <iostream>

using namespace std;

int nums[1025][1025];

int N,M;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	
	// 입력과 동시에 누적 합
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int tmp;
			cin >> tmp;
			nums[i][j] = nums[i - 1][j] + nums[i][j - 1] + tmp - nums[i - 1][j - 1];
		}
	}

	int x1, y1, x2, y2;

	// 누적합의 성질에 의해 특정값을 구하려면 적절한 뺄셈이 되야함.
	for (int i = 0; i < M; i++) {
		int ans;
		cin >> x1 >> y1 >> x2 >> y2;
		ans = nums[x2][y2] - nums[x1 - 1][y2] - nums[x2][y1 - 1] + nums[x1 - 1][y1 - 1];
		cout << ans << '\n';
	}
	
	return 0;
}
