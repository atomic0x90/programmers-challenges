#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

bool compare(pair<string,int> a, pair<string,int> b){
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    vector<pair<string,pair<pair<int,int>,pair<int,int> > > > v;
    vector<pair<string,int> > sum;
    for(int i = 0;i < genres.size();i++){
        int flag = -1;
        for(int j = 0;j < v.size();j++){
            if(v[j].first == genres[i]){
                flag = j;
                break;
            }
        }
        if(flag == -1) v.push_back(make_pair(genres[i],make_pair(make_pair(plays[i],i),make_pair(-1,-1))));
        else{
            if(v[flag].second.second.first == -1){
                if(v[flag].second.first.first > plays[i]){
                    v[flag].second.second.first = plays[i];
                    v[flag].second.second.second = i;
                }
                else{
                    v[flag].second.second.first = v[flag].second.first.first;
                    v[flag].second.second.second = v[flag].second.first.second;
                    v[flag].second.first.first = plays[i];
                    v[flag].second.first.second = i;
                }
            }
            else{
                if(v[flag].second.first.first < plays[i]){
                    v[flag].second.second.first = v[flag].second.first.first;
                    v[flag].second.second.second = v[flag].second.first.second;
                    v[flag].second.first.first = plays[i];
                    v[flag].second.first.second = i;
                }
                else if(v[flag].second.first.first >= plays[i] && v[flag].second.second.first < plays[i]){
                    v[flag].second.second.first = plays[i];
                    v[flag].second.second.second = i;
                }
            }
        }
    }
    for(int i = 0;i < v.size();i++){
        int num = 0;
        for(int j = 0;j < genres.size();j++){
            if(genres[j] == v[i].first) num += plays[j];
        }
        sum.push_back(make_pair(v[i].first,num));
    }
    
    sort(sum.begin(),sum.end(),compare);
    
    for(int i = 0;i < sum.size();i++){
        int check = 0;
        for(int j = 0;j < v.size();j++){
            if(sum[i].first == v[j].first){
                check = j;
                break;
            }
        }
        answer.push_back(v[check].second.first.second);
        if(v[check].second.second.first != -1) answer.push_back(v[check].second.second.second);
    }
    return answer;
}
