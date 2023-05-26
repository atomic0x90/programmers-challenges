#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

bool compare(pair<int,int> &a, pair<int,int> &b){
    if(a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

int solution(vector<vector<int>> targets) {
    int answer = 1;
    vector<pair<int,int>> v;
    
    for(int i = 0;i < targets.size();i++) v.push_back(make_pair(targets[i][0],targets[i][1]));
    
    sort(v.begin(),v.end(),compare);
    
    int start = v[0].first;
    int end = v[0].second;
    
    for(int i = 1;i < v.size();i++){
        if(v[i].first < end) end = min(end,v[i].second);
        else{
            start = v[i].first;
            end = v[i].second;
            answer++;
        }
    }
    
    return answer;
}
