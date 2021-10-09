#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

int solution(string begin, string target, vector<string> words) {
    if(find(words.begin(),words.end(),target) == words.end()) return 0;
    
    queue<pair<string,int> > q;
    q.push(make_pair(begin,0));
    
    while(!q.empty()){
        string s = q.front().first;
        int num = q.front().second;
        q.pop();
        
        for(int i = 0;i < s.size();i++){
            if(s[i] != target[i]){
                string ts = s;
                
                for(int j = 0;j < 26;j++){
                    ts[i] = 'a'+j;
                    if(ts == s) continue;
                    
                    if(find(words.begin(),words.end(),ts) != words.end()){
                        if(ts == target) return num+1;
                    
                        q.push(make_pair(ts,num+1));
                    }
                }    
            }
        }
    }
    return 0;
}
