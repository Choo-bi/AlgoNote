# bj_1991(Tree)

[https://www.acmicpc.net/problem/1991](https://www.acmicpc.net/problem/1991)

```cpp
#include <iostream>
#include <vector>

using namespace std;

int N;
pair<int, int> p[26];

// 전위
void preorder(int node) {
	if (node != '.') {
		cout << char(node);
		preorder(p[node - 65].first);
		preorder(p[node - 65].second);
	}
}

// 중위
void inorder(int node) {
	if (node != '.') {
		inorder(p[node - 65].first);
		cout << char(node);
		inorder(p[node - 65].second);
	}
}

// 후위
void postorder(int node) {
	if (node != '.') {
		postorder(p[node - 65].first);
		postorder(p[node - 65].second);
		cout << char(node);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	// 페어배열로 트리 형태 만들기
	for (int i = 0; i < N; i++) {
		char value, left, right;
		cin >> value >> left >> right;
		p[value - 65] = { left,right };
	}
	preorder('A');
	cout << '\n';
	inorder('A');
	cout << '\n';
	postorder('A');

	return 0;
}
```

배열로 트리형태를 만들고, 페어로 자식 노드를 구현하여 트리를 구현하였다. 순회방법은 재귀형태로 손쉽게 구현 가능.

### 내가 헤맨 부분

- 트리 형태 구현(구조체로 만들까 했는데 입력부분에서 너무 헤매서 다른