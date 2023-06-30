#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    queue <int> qq;
    int N;
    cin >> N;
    while (N) {
   
        string command;
        cin >> command;
        if(command == "push") {
            int p;
            cin >> p;
            qq.push(p);
        }
        else if (command == "front") {
            if (qq.size()) {
                cout << qq.front() << '\n';
            }
            else
                cout << -1 << '\n';
            
        }
        else if (command == "back") {
            if (qq.size()) {
                cout << qq.back() << '\n';
            }
            else
                cout << -1 << '\n';
        }
        else if (command == "size") {
            cout << qq.size() << '\n';
        }
        else if (command == "pop") {
            if (qq.size()) {
                cout << qq.front() << '\n';
                qq.pop();
            }
            else
                cout << -1 << '\n';
        }
        else if (command == "empty") {
            cout << qq.empty() <<'\n';
        }

        N--;
    }
}