#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    set<string> s;
    
    for(int i = 0;i < gems.size();i++) s.insert(gems[i]);
    
    int start = 1,end = 1,check = 100002;
    
    map<string,int> m;
    m.insert(make_pair(gems[0],1));
    
    while(end <= gems.size()){
        if(m.size() == s.size()){
            if(check > end-start+1){
                if(answer.size() == 0){
                    answer.push_back(start);
                    answer.push_back(end);
                    check = end-start+1;
                }
                else{
                    answer.clear();
                    answer.push_back(start);
                    answer.push_back(end);
                    check = end-start+1;
                }
            }
            else if(check == end-start+1){
                if(start < answer[0]){
                    answer.clear();
                    answer.push_back(start);
                    answer.push_back(end);
                }
            }
            if(m.find(gems[start-1])->second == 1) m.erase(m.find(gems[start-1]));
            else m.find(gems[start-1])->second--;
            
            start++;
        }
        else{
            if(end == gems.size()) break;
            
            end++;
            
            if(m.find(gems[end-1]) == m.end()) m.insert(make_pair(gems[end-1],1));
            else m.find(gems[end-1])->second++;
        }
    }
    
    return answer;
}
