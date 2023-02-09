#include <string>
#include <vector>
#include <set>
using namespace std;

vector<int>check;
set<string>s;
vector<string>id;
vector<string>bid;

void algo(int ban){
    if(bid.size() == ban){
        string st = "";
        
        for(int i = 0;i < check.size();i++) st += char(check[i]);
        
        s.insert(st);
        
        return;
    }
    
    for(int i = 0;i < id.size();i++){
        if(check[i] == 1) continue;
        if(bid[ban].size() != id[i].size()) continue;
        
        bool flag = true;
        
        for(int k = 0;k < id[i].size();k++){
            if(bid[ban][k] == '*') continue;
            
            if(bid[ban][k] != id[i][k]){
                flag = false;
                break;
            }
        }
        
        if(flag){
            check[i] = 1;

            algo(ban+1);

            check[i] = 0;
        }
    }
    
    return;
}

int solution(vector<string> user_id, vector<string> banned_id) {
    id = user_id;
    bid = banned_id;
    check = vector<int>(user_id.size(),0);
    algo(0);
    return s.size();
}
