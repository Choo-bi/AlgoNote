#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<int> a(1000001);

	a[1] = 0;
	a[2] = 1;
	a[3] = 1;

	for (int i = 2; i < a.capacity(); i++) {
		// 1을 뺀다.
		a[i] = a[i - 1] + 1;

		// 2로 나누어지면 최소 비교
		if (i % 2 == 0) {
			a[i] = min(a[i], a[i / 2] + 1);
		}

		// 3으로 나누어지면 최소 비교
		if (i % 3 == 0) {
			a[i] = min(a[i], a[i / 3] + 1);
		}
	}

    int N;
    cin >> N;
    
    cout << a[N];
}