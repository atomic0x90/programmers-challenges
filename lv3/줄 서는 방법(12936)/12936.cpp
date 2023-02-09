#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<int> v;
    long long check = 1;
    for(int i = 1;i < n;i++) check *= i;
    for(int i = 1;i <= n;i++) v.push_back(i);
    
    int len = n-1;
    
    while(v.size() != 1){
        for(int i = 1;i <= v.size();i++){
            if(i*check >= k){
                answer.push_back(v[i-1]);
                v.erase(v.begin()+i-1);
                k -= (i-1)*check;
                check /= (len--);
                break;
            }
        }
    }
    
    answer.push_back(v[0]);
    
    return answer;
}
