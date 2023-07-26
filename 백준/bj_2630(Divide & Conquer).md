# bj_2630(Divide & Conquer)

[https://www.acmicpc.net/problem/2630](https://www.acmicpc.net/problem/2630)

```cpp
#include <iostream>

using namespace std;

int pp[129][129];

int white = 0, blue = 0;

void div(int X, int Y, int s) {
    int color = pp[Y][X];
    bool flag = false;
    for (int i = Y; i < Y + s; i++) {
        for (int j = X; j < X + s; j++) {
            if (color != pp[i][j]) {
                flag = true;
                break;
            }
        }
    }
    if (flag) {
        div(X, Y, s / 2);
        div(X + s/2, Y, s / 2);
        div(X, Y + s/2, s / 2);
        div(X + s/2, Y + s/2, s / 2);
    }
    else {
        if (color == 1) blue++;
        else white++;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> pp[i][j];
        }
    }
    div(0, 0, N);
    cout << white << '\n' << blue;

    return 0;
}
```

## 내가 헤맸던 부분

div 메소드의 재귀와 반복문 파트의 인덱스 지정부분의 올바른 값을 찾는데 시간이 걸림.

 

### 풀이

(입력받는 파트는 생략).

1. 이중 반복문을 통해 입력받은 배열을 순회하며 첫 인덱스와 다른 원소값을 가진 인덱스가 탐색되면 반복문을 중단.
2. 중단된 반복문은 플래그가 활성화.
3. 탐색범위를 4등분하여 1~3번 과정 반복
4. 이중반복문이 중단되지 않는다면, 탐색범위안에선 모두 같은 색인 것이므로 색종이 갯수를 카운트한다.