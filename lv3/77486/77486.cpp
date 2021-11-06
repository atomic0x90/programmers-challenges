#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer(enroll.size(),0);
    vector<int> name(enroll.size(),-1);
    
    for(int i = 0;i < enroll.size();i++){
        if(referral[i] == "-") continue;
        name[i] = find(enroll.begin(),enroll.end(),referral[i])-enroll.begin();
    }
    
    for(int i = 0;i < seller.size();i++){
        int income = amount[i]*100;
        auto iter = find(enroll.begin(),enroll.end(),seller[i])-enroll.begin();
        while(true){
            int location = iter;
            int remain = income*0.1;
            
            if(income < 10){
                answer[location] += income;
                break;
            }
            
            answer[location] += (income-remain);
            income = remain;
            
            if(referral[location] == "-") break;
            
            iter = name[location];
        }
    }
    return answer;
}
