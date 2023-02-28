#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <utility>
#include <map>
#include <math.h>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    vector<pair<string,string>> v;
    map<string,int> m;
    
    for(int i = 0;i < records.size();i++){
        stringstream ss(records[i]);
        string time,num,state;
        ss>>time>>num>>state;
        
        if(state == "IN") v.push_back(make_pair(time,num));
        else{
            for(int j = 0;j < v.size();j++){
                if(v[j].second == num){
                    int inTime = (stoi(v[j].first.substr(0,2))*60) + stoi(v[j].first.substr(3));
                    int outTime = (stoi(time.substr(0,2))*60) + stoi(time.substr(3));
                    int totalTime = outTime - inTime;
                    
                    v[j].second = "x";
                    
                    if(m.find(num) == m.end()) m.insert(make_pair(num,totalTime));
                    else m.find(num)->second += totalTime;
                }
            }
        }
    }
    
    for(int i = 0;i < v.size();i++){
        if(v[i].second.size() == 4){
            int outTime = ((23*60)+59)-((stoi(v[i].first.substr(0,2))*60) + stoi(v[i].first.substr(3)));
            if(m.find(v[i].second) != m.end()) m.find(v[i].second)->second += outTime;
            else m.insert(make_pair(v[i].second,outTime));
        }
    }
    
    for(auto iter = m.begin();iter != m.end();iter++){
        if(iter->second <= fees[0]) answer.push_back(fees[1]);
        else answer.push_back(fees[1] + 
                              ((iter->second-fees[0])/fees[2] + ((iter->second-fees[0])%fees[2] != 0 ? 1 : 0))*fees[3]);
    }
    
    return answer;
}
