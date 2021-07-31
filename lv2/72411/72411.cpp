#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    vector<string> ts;
    vector<int> ind;
    map<string,int> m;
    
    for(int i = 0;i < orders.size();i++)
        sort(orders[i].begin(),orders[i].end());
    
    for(int i = 0;i < course.size();i++){
        m.clear();
        
        for(int j = 0;j < orders.size();j++){
            if(course[i] > orders[j].size()) continue;
            
            ind.clear();
            
            for(int k = 0;k < orders[j].size();k++) ind.push_back(0);
            for(int k = 0;k < course[i];k++) ind[k] = 1;
            
            sort(ind.begin(),ind.end());
            
            do{
                string s = "";
                for(int k = 0;k < ind.size();k++){
                    if(ind[k] == 1) s += orders[j][k];
                }
                
                if(m.find(s) == m.end()) m.insert(make_pair(s,1));
                else m.find(s)->second++;
            }while(next_permutation(ind.begin(),ind.end()));
        }
        int max = 0;
        ts.clear();

        for(auto it = m.begin(); it != m.end(); it++){
            if(it->second > max && it->second > 1){
                ts.clear();
                ts.push_back(it->first);
                max = it->second;
            }
            else if(it->second == max) ts.push_back(it->first);
        }

        for(int k = 0;k < ts.size();k++) answer.push_back(ts[k]);
    }
    sort(answer.begin(),answer.end());
    return answer;
}
