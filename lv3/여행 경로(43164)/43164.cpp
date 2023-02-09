#include <string>
#include <vector>

using namespace std;

vector<string> vs;
vector<string> result;
string ts = "";

void algo(vector<int> v,vector<vector<string> > ti){
    int num = 0;
    for(int i = 0;i < v.size();i++){
        if(v[i] == 1) num++;
        else break;
    }
    if(num == v.size()){
        if(ts == ""){
            for(int i = 0;i < vs.size();i++) ts += vs[i];
            
            result = vs;
            
            return;
        }
        else{
            string tmp = "";
            for(int i = 0;i < vs.size();i++) tmp += vs[i];
            
            if(ts > tmp){
                ts = tmp;
                result = vs;
            }
            return;
        }
    }
    
    for(int i = 0;i < ti.size();i++){
        if(v[i] == 0 && vs.back() == ti[i][0]){
            vs.push_back(ti[i][1]);
            v[i] = 1;
            algo(v,ti);
            v[i] = 0;
            vs.pop_back();
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<int> v(tickets.size(),0);
    vs.push_back("ICN");
    algo(v,tickets);
    
    return result;
}
