#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, R;
	cin >> T;
	string S;
	for (int i = 0; i < T; i++) {
		cin >> R >> S;
		for (int j = 0; j < S.length(); j++) {
			for (int k = 0; k < R; k++) {
				cout << S[j];
			}
		}
		cout << '\n';
	}
	
	return 0;
}