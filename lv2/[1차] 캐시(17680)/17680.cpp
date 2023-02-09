#include <string>
#include <vector>
#include <cctype>
#include <utility>
#include <algorithm>
using namespace std;

bool compare(pair<string,int> a,pair<string,int> b){
    return a.second < b.second;
}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<pair<string,int> > v;
    for(int i = 0;i < cities.size();i++){
        for(int j = 0;j < cities[i].size();j++) cities[i][j] = tolower(cities[i][j]);
    }
    
    for(int i = 0;i < cities.size();i++){
        if(v.size() == 0 && cacheSize != 0){
            answer += 5;
            v.push_back(make_pair(cities[i],1));
        }
        else if(v.size() == 0 && cacheSize == 0){
            answer = cities.size()*5;
            break;
        }
        else{
            int flag = 0;
            for(int j = 0;j < v.size();j++){
                if(v[j].first == cities[i]){
                    flag = 1;
                    break;
                }
            }
            
            if(flag == 0){
                for(int j = 0;j < v.size();j++) v[j].second++;
                
                answer += 5;
                
                if(v.size() == cacheSize){
                    sort(v.begin(),v.end(),compare);
                    if(v.size()) v.pop_back();
                }
                
                v.push_back(make_pair(cities[i],1));
            }
            else if(flag == 1){
                answer++;
                for(int j = 0;j < v.size();j++){
                    if(v[j].first == cities[i]) v[j].second = 1;
                    else v[j].second++;
                }
            }
        }
    }
    
    return answer;
}
