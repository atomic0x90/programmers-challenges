#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <stack>

using namespace std;

bool compare(const pair<string,pair<int,int>> &a, const pair<string,pair<int,int>> &b){
    return a.second.first < b.second.first;
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    vector<pair<string,pair<int,int>>> v;
    stack<pair<string,pair<int,int>>> s;
    
    for(int i = 0;i < plans.size();i++){
        string h,m;
        h = plans[i][1].substr(0,2);
        m = plans[i][1].substr(3,5);
        
        int nowTime,howTime;
        nowTime = 60*stoi(h) + stoi(m);
        howTime = stoi(plans[i][2])-1;
        
        v.push_back(make_pair(plans[i][0],make_pair(nowTime,howTime)));
    }
    
    sort(v.begin(),v.end(),compare);
    
    int now = 0;
    bool flag = false;
    pair<string,pair<int,int>> tmp;
    
    for(int i = v[0].second.first;;i++){
        
        if(tmp.second.second == 0){
            flag = false;
            if(tmp.first != ""){
                answer.push_back(tmp.first);
                tmp.first = "";
            }
        }
        if(now >= v.size()) break;
        if(!flag){
            if(v[now].second.first == i){
                tmp.first = v[now].first;
                tmp.second.first = v[now].second.first;
                tmp.second.second = v[now].second.second;
                flag = true;
                now++;
            }
            else{
                if(!s.empty()){
                    tmp.first = s.top().first;
                    tmp.second.first = s.top().second.first;
                    tmp.second.second = s.top().second.second-1;
                    flag = true;
                    s.pop();
                }
            }
        }
        else{
            if(tmp.second.second != 0){
                if(v[now].second.first == i){
                    s.push(make_pair(tmp.first,make_pair(tmp.second.first,tmp.second.second)));
                    tmp.first = v[now].first;
                    tmp.second.first = v[now].second.first;
                    tmp.second.second = v[now].second.second;
                    now++;
                }
                else tmp.second.second--;
            }
            else{
                answer.push_back(tmp.first);
                if(s.empty()){
                    flag = false;
                }
                else{
                    tmp.first = s.top().first;
                    tmp.second.first = s.top().second.first;
                    tmp.second.second = s.top().second.second;
                    s.pop();
                }
            }
        }
        
    }
    
    if(tmp.second.second > 0) answer.push_back(tmp.first);
    
    while(!s.empty()){
        answer.push_back(s.top().first);
        s.pop();
    }
    
    return answer;
}
