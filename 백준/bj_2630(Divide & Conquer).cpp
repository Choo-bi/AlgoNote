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