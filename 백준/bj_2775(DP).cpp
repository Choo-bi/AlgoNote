#include <iostream>

using namespace std;

int aaa[15][15];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int a, b;
		cin >> a >> b;
		for (int i = 0; i <= a; i++) {	
			for (int j = 1; j <= b; j++) {
				if (i == 0) aaa[0][j] = j;
				else if (j == 1) aaa[i][1] = 1;
				else aaa[i][j] = aaa[i][j - 1] + aaa[i - 1][j];
			}
		}
		cout << aaa[a][b] << '\n';
	}
	
	return 0;
}