#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, T;
    cin >> N >> T;
    //문자열 또는 번호를 key로 하는 맵을 만들기
    map<int, string> dogam1;
    map<string, int> dogam2;

    for (int i = 1; i <= N; i++) {
        string name;
        cin >> name;
        dogam1.insert({i,name });
        dogam2.insert({name, i });
    }
    // 입력값이 숫자면 dogam1, 문자열이면 dogam2
    for (int i = 0; i < T; i++) {
        string s;
        cin >> s;
        if (isdigit(s[0]))
            cout << dogam1.find(stoi(s))->second << '\n';
        else
            cout << dogam2.find(s)->second << '\n';
    }
	return 0;
}