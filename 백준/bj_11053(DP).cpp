#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int N;
vector<int> A(1000);

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	int aa[1000];
	int m = 0;
	for (int i = 0; i < N; i++) {
		aa[i] = 1;
		for (int j = 0; j < i; j++) {
			if (A[i] > A[j]) {
				aa[i] = max(aa[i], aa[j] + 1);
			}
		}
		m = max(m, aa[i]);
	}
	cout << m;

	return 0;
}