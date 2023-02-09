#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

bool compare(const pair<double,int> &a, const pair<double,int> &b){
    return a.first > b.first;
}

vector<int> solution(vector<vector<int>> score) {
    vector<int> answer(score.size());
    vector<pair<double,int> > average;
    
    for(int i = 0;i < score.size();i++)
        average.push_back(make_pair((score[i][0]+score[i][1])/2.0,i));
    
    sort(average.begin(),average.end(),compare);
    
    int rank = 1;
    int duplication = 0;
    
    answer[average[0].second] = 1;
    for(int i = 1;i < average.size();i++){
        if(average[i-1].first == average[i].first){
            answer[average[i].second] = rank;
            duplication++;
        }
        else{
            answer[average[i].second] = rank+duplication+1;
            rank += duplication+1;
            duplication = 0;
        }
    }
    
    return answer;
}
