#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    vector<int> v;

    sort(tangerine.begin(),tangerine.end());
    
    int check = 1;
    
    for(int i = 1;i < tangerine.size();i++){
        if(tangerine[i] == tangerine[i-1]) check++;
        else{
            v.push_back(check);
            check = 1;
        }
    }
    
    v.push_back(check);
    
    sort(v.begin(),v.end());
    
    while(k > 0){
        k -= v.back();
        v.pop_back();
        answer++;
    }

    return answer;
}
