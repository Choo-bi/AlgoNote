#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;
 
    
    if (N >= 125) {
        cout << N / 5 + N / 25 + N/125;
    }
    else if (N >= 25) {
        cout << N / 5 + (N / 25);
    }
    else
        cout << N / 5;

    return 0;
}