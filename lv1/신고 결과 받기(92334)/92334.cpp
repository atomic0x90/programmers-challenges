#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(),0);
    vector<pair<string,int>> v;
    for(int i = 0;i < id_list.size();i++) v.push_back(make_pair(id_list[i],0));
    
    sort(report.begin(),report.end());
    
    report.erase(unique(report.begin(),report.end()),report.end());
    
    for(int i = 0;i < report.size();i++){
        stringstream ss(report[i]);
        string s;
        ss>>s;
        ss>>s;
        for(int j = 0;j < v.size();j++){
            if(v[j].first == s){
                v[j].second++;
                break;
            }
        }
    }
    
    for(int i = 0;i < report.size();i++){
        stringstream ss(report[i]);
        string s;
        string t;
        ss>>s;
        ss>>t;
        for(int j = 0;j < v.size();j++){
            if(v[j].first == t){
                if(v[j].second >= k){
                    for(int o = 0;o < id_list.size();o++){
                        if(id_list[o] == s){
                            answer[o]++;
                        }
                    }
                }
            }
        }
    }
    return answer;
}
