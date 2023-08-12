#include <iostream>
#include <algorithm>

using namespace std;

int sticker[2][100000];

int aaa[2][100000];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int n;
		cin >> n;
		// 점수 입력
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				int score;
				cin >> score;
				sticker[i][j] = score;
			}
		}

		// 기저상태 (처음 시작은 첫 열 중 하나를 선택해야함)
		aaa[0][0] = sticker[0][0];
		aaa[1][0] = sticker[1][0];
		aaa[1][1] = aaa[0][0] + sticker[1][1];
		aaa[0][1] = aaa[1][0] + sticker[0][1];

		// 점화식(각 위치의 스티커를 때는 상황의 경우의 수를 고려하여 최대인 것을 선택)
		for (int i = 2; i < n; i++) {
			aaa[0][i] = sticker[0][i] + max(aaa[1][i - 1], aaa[1][i - 2]);
			aaa[1][i] = sticker[1][i] + max(aaa[0][i - 1], aaa[0][i - 2]);
		}
		cout << max(aaa[1][n - 1], aaa[0][n - 1]) << '\n';

	}
	



	return 0;
}
