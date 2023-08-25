#include <iostream>

using namespace std;

int A, B, V;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    
    cin >> A >> B >> V;
    int day = 1;
    // 목표 : V-A까지만 가면 다음날 아침에 A만큼 올라서 정상에 감
    day += (V - A) / (A - B);
    if ((V - A) % (A - B) != 0)
        day++;
    if (A >= V)
        cout << "1";
    else
        cout << day;
	return 0;
}