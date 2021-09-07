#include <string>
#include <vector>
#include <stack>
#include <utility>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    stack<pair<int,int> > s;
    
    for(int i = 0;i < prices.size();i++){
        if(s.empty()) s.push(make_pair(prices[i],i));
        else{
            if(s.top().first <= prices[i]) s.push(make_pair(prices[i],i));
            else{
                while(!s.empty()){
                    if(s.top().first > prices[i]){
                        answer[s.top().second] = i - s.top().second;
                        s.pop();
                    }
                    else break;
                }
                
                s.push(make_pair(prices[i],i));
            }
        }
    }
    
    while(!s.empty()){
        answer[s.top().second] = prices.size()-1 - s.top().second;
        s.pop();
    }
    
    return answer;
}
