#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

bool compare(const pair<int,int> &a, const pair<int,int> &b){
    return a.first < b.first;
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    int time = 0;
    vector<pair<int,int>> v;
    vector<int> roomTime;
    
    for(int i = 0;i < book_time.size();i++)
        v.push_back(
                    make_pair(
                                (stoi(book_time[i][0].substr(0,2))*60)+stoi(book_time[i][0].substr(3)),
                                (stoi(book_time[i][1].substr(0,2))*60)+stoi(book_time[i][1].substr(3))+10
                            )
                    );
    sort(v.begin(),v.end(),compare);
    
    for(time = v[0].first;time <= (23*60)+59;time++){
        sort(roomTime.begin(),roomTime.end(),greater<int>());
        while(roomTime.size() && roomTime.back() <= time) roomTime.pop_back();
        
        for(int i = 0;i < v.size();i++){
            if(v[i].first == time) roomTime.push_back(v[i].second);
            else if(v[i].first > time) break;
        }
        answer = max(answer,int(roomTime.size()));
    }
    
    return answer;
}
