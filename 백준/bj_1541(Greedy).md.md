# bj_1541(Greedy)

[https://www.acmicpc.net/problem/1541](https://www.acmicpc.net/problem/1541)

```jsx
#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	cin >> s;
	bool isMinus = false;
	string temp="";
	int result = 0;

	/* 입력받은 문자열이 숫자가 아닐 때가지 temp변수에 숫자 채워넣어서 피연산자 구분
	*  - 가 나오면 그 뒤에나오는 모든 수는 음수처리해야 최소값이 됨(-뒤에 모두 괄호처리)
	*/ 
	for (int i = 0; i <= s.size(); i++) {
		if (s[i] == '+'|| s[i] == '-'|| s[i]=='\0') {
			if (isMinus)
				result -= stoi(temp);
			else
				result += stoi(temp);
			temp = "";
			if (s[i] == '-')
				isMinus = true;	
		}
		else
			temp += s[i];
	}
	cout << result;

	return 0;
}
```

문자열 파싱하는 부분에서 많이 시간이 걸렸던 문제. 괄호처리 자체는 간단한 수학 연산이라 파싱이 문제핵심이었다.

### 헤맨 부분

- 입력받은 문자열에서 숫자 구분 처리