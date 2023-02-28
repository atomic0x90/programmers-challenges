#include <string>
#include <vector>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    for(int i = 0;i < discount.size()-9;i++){
        int check = 10;
        vector<int> tnum = number;
        for(int j = i;j < i+10;j++){
            bool flag = true;
            for(int k = 0;k < want.size();k++){
                if(want[k] == discount[j]){
                    if(tnum[k] == 0) break;
                    
                    tnum[k]--;
                    flag = false;
                    check--;
                    break;
                }
            }
            if(flag) break;
        }
        
        bool check0 = true;
        
        for(int j = 0;j < tnum.size();j++){
            if(tnum[j] != 0) check0 = false;
        }
        
        if(check0) answer++;
    }
    return answer;
}
