#include <iostream>
#include <algorithm>

using namespace std;

int N;
int RGB[1000][3];
// 누적 합으로 비교하기위해 선언
int acc[1000][3];

int min(int a, int b) {
	return a<b?a:b;
}

int min(int a, int b, int c) {
	int p = min(a, b);
	return min(p, c);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> RGB[i][j];
		}
	}
	
	for (int i = 0; i < 3; i++) {
		acc[0][i] = RGB[0][i];
	}
	
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			if(j == 0)
				acc[i][j] = RGB[i][j] + min(acc[i - 1][j + 1], acc[i - 1][j + 2]);
			else if(j == 1)
				acc[i][j] = RGB[i][j] + min(acc[i - 1][j - 1], acc[i - 1][j + 1]);
			else 
				acc[i][j] = RGB[i][j] + min(acc[i - 1][j - 1], acc[i - 1][j -2]);
		}
	}
	cout << min(acc[N - 1][0], acc[N - 1][1], acc[N - 1][2]);
	
	return 0;
}