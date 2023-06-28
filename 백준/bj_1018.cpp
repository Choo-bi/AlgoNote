#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    // 2차원 벡터를 사용하여 배열 선언
    vector<vector<char>> arr(N, vector<char>(M));
    vector<vector<char>> prr(N, vector<char>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }
		// 수정할 체스판을 따로 복사
    prr = arr;
		// 일일히 하나의 정사각형마다 앞에 것과 비교하며 검사
    int minCount = 32;
    for (int i = 0; i < N-8+1; i++) {
        for (int j = 0; j < M-8+1; j++) {
            int bw = 2; 
            // 시작이 W,B일때 두가지 경우 고려
            while (bw) {
                int cnt = 0;
                char start;
                if (bw % 2)
                    start = 'B';
                else
                    start = 'W';
                
                for (int k = 0; k < 8; k++) {
                    
                    if (k) {
                        if (prr[i + k][j] == prr[i+k-1][j]) {
                            cnt++;
                            prr[i + k][j] = (prr[i + k - 1][j] == 'W' ? 'B' : 'W');
                        }
                    }
                    else
                    {
                        if (prr[i][j] != start)
                        {
                            cnt++;
                            prr[i][j] = start;
                        }

                    }
                    for (int t = 1; t < 8; t++) {
                        if (prr[i + k][j + t] == prr[i + k][j + t - 1]) {
                            cnt++;
                            prr[i + k][j+t] = (prr[i + k][j+t-1] == 'W' ? 'B' : 'W');
                        }
                    }
                }
                bw--;
                if (minCount > cnt)
                    minCount = cnt;
                prr = arr;
            }
            
        }

    }
    cout << minCount;

    return 0;
}