# PR Lv.2 귤고르기

[https://school.programmers.co.kr/learn/courses/30/lessons/138476](https://school.programmers.co.kr/learn/courses/30/lessons/138476)

```cpp
#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(int k, vector<int> tangerine) {
	int answer = 0;
	map<int, int> m;
	for(auto it = tangerine.begin(); it!=tangerine.end(); it++){
		m[*it] += 1;
}
map<int, int >::iterator it;
// 루프를 통해 개수가 가장 많은 사이즈를 얻어 k에서 빼는 방식
// k값이 감소할 때마다 가짓수는 증가하는 방식
while(1){
	int maxValue = 0;
	int maxKey = 0;
    if(k>0){
        for(it = m.begin(); it != m.end(); it++){
            if(it->second > maxValue){
                maxValue = it->second;
                maxKey = it->first;
            }
        }
        m.erase(maxKey);
        k -= maxValue;
        answer++;
    }
    else
        break;

}
return answer;

}
```

위 방식은 비효율적인 접근이 많이 포함되있으므로 몇몇 테스트 케이스에서 시간초과가  나는 것을 볼 수 있었음.

map을 value 기준으로 내림차순으로 정렬할 수 있으면 훨씬 최적화가 될 거라고 생각.

map은 바로 value 기준으로 내림차순으로 못하므로 vector <pair<int,int>>로 변경하여 진행.

```cpp
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
```