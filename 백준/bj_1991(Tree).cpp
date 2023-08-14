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
