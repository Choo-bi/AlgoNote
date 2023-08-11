#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;

// 입력 삼각형
vector<int> tri[501];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	// 입력
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			int temp;
			cin >> temp;
			tri[i].push_back(temp);
		}
	}

	// 누적합(최대) 삼각형 형태로 구성
	for (int i = 1; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0)
				tri[i][j] += tri[i - 1][j];
			else if (j == i)
				tri[i][j] += tri[i - 1][j - 1];
			else
				tri[i][j] += max(tri[i - 1][j - 1], tri[i - 1][j]);
		}
	}

	// 최대값 출력
	int M=0;
	for (int i = 0; i < N; i++) {
		if (M < tri[N - 1][i])
			M = tri[N - 1][i];
	}
	cout << M;

	return 0;
}
