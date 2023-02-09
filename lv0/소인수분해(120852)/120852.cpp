#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    vector<int> tmp;
    bool flag = true;
    
    while(flag){
        flag = false;
        
        for(int i = 2;i < n;i++){
            if(n%i == 0){
                tmp.push_back(i);
                flag = true;
                n /= i;
                break;
            }
        }
        
        if(!flag) tmp.push_back(n);
    }
    
    answer.push_back(tmp[0]);
    for(int i = 1;i < tmp.size();i++)
        if(answer.back() != tmp[i]) answer.push_back(tmp[i]);
    
    return answer;
}
