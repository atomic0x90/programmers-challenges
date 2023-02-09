#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

bool compare(const pair<int,int> &a, const pair<int,int> &b){
    return a.first > b.first;
}

vector<int> solution(vector<int> emergency) {
    vector<int> answer(emergency.size());
    vector<pair<int,int> > v(emergency.size());
    
    for(int i = 0;i < emergency.size();i++)
        v[i] = make_pair(emergency[i],i);
    
    sort(v.begin(),v.end(),compare);
    
    for(int i = 0;i < v.size();i++)
        answer[v[i].second] = i+1;
    
    return answer;
}
