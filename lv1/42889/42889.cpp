#include <string>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

vector <pair<int,int>> state;

bool compare(const pair<double,int> &a,const pair<double,int> &b){
    if(a.first > b.first) return true;
    else if(a.first == b.first){
        if(a.second > b.second) return false;
        else return true;
    }
    else return false;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector <pair<double,int>> result;
    state.resize(N+1);
    
    for(int i = 0;i < stages.size();i++){
        if(stages[i] != N+1){
            for(int j = 1;j <= stages[i];j++)
                state[j].second++;
            
            state[stages[i]].first++;
        }
        else{
            for(int j = 1;j < N+1;j++)
                state[j].second++;
        }
    }
    
    for(int i = 1;i < N+1;i++){
        if(state[i].second != 0)
            result.push_back(make_pair((double)state[i].first/(double)state[i].second,i));
        else
            result.push_back(make_pair(0,i));
    }
    
    sort(result.begin(),result.end(),compare);
    
    for(int i = 0;i < N;i++)
        answer.push_back(result[i].second);
    
    return answer;
}
