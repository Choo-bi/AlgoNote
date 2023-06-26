#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

static bool comp(pair<int, int>& a, pair<int, int>& b){
	return a.second > b.second;
}

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    map<int, int > m; 
    sort(tangerine.begin(),tangerine.end());
    for(auto it = tangerine.begin(); it!=tangerine.end(); it++){
        m[*it] += 1;
    }
    // 최적화를 위해 map을 vector로  변경하고, value기준으로 내림차순 정렬
    // 루프를 통해 개수가 가장 많은 사이즈를 얻어 k에서 빼는 방식
    // k값이 감소할 때마다 가짓수는 증가하는 방식
    vector<pair<int,  int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), comp);
    vector<pair<int,int>>::iterator it;
    bool flag = true;
    while(k>0 && flag){
        int maxValue = 0;
        int maxKey =0;
        for(it = v.begin(); it != v.end(); it++){
            if(it->second > maxValue){
                maxValue = it->second;
                maxKey = it->first;
                if(maxValue > k){
                    flag = !flag;
                    break;
                }
            }   
        }
        //maxValue 인덱스 삭제
        for (auto it = v.begin(); it != v.end();it++) {
            if (it->first == maxKey && it->second == maxValue) {
                it = v.erase(it);
            }
        }
        k -= maxValue;
        answer++;
    }
    return answer;
}