#include <iostream>

using namespace std;

unsigned long long A, B, C;
int sol(int cnt) {

	if (cnt == 1) 
		return A % C;

	unsigned long long ans = sol(cnt / 2) % C;

	if (cnt % 2 == 0) 
		return ans * ans % C;
	else 
		return ans * ans % C * A % C;
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> A >> B >> C;
	cout << sol(B);

	return 0;
}
