#include <iostream>
#include <string>

using namespace std;

int aaa[15][15];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	
	int cnt = 666;
	string s;
	while (N > 0) {
		s = to_string(cnt);
		// 666이 숫자에 포함됐을 때 카운트다운
		if (s.find("666") != string::npos) N--;
		cnt++;
	}
	cout << s;
	return 0;
}