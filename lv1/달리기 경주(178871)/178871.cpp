#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    map<string,int> m1;
    map<int,string> m2;
    
    for(int i = 0;i < players.size();i++){
        m1.insert(make_pair(players[i],i));
        m2.insert(make_pair(i,players[i]));
    }
    
    for(int i = 0;i < callings.size();i++){
        int index = m1[callings[i]];
        string s = m2[index-1];
        
        m2[index-1] = callings[i];
        m2[index] = s;
        
        m1[callings[i]] = index-1;
        m1[s] = index;
    }
    
    for(auto it = m2.begin();it != m2.end();it++) answer.push_back(it->second);
    
    return answer;
}
