#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    vector<pair<int,int> > v;
    
    for(int i = 0;i < priorities.size();i++) v.push_back(make_pair(priorities[i],i));
    
    sort(priorities.begin(),priorities.end(),greater<int>());
    
    while(!v.empty()){
        if(v.front().first == priorities.front()){
            answer++;
            if(v.front().second == location) break;
            
            v.erase(v.begin(),v.begin()+1);
            priorities.erase(priorities.begin(),priorities.begin()+1);
        }
        else{
            v.push_back(v.front());
            v.erase(v.begin(),v.begin()+1);
        }
    }
    
    
    return answer;
}
