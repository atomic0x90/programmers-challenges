#include <string>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int now = 0;
    vector<int> time;
    
    while(jobs.size()){
        int m = INT_MAX;
        int check = -1;
        for(int i = 0;i < jobs.size();i++){
            if(now >= jobs[i][0] && m > jobs[i][1]){
                m = jobs[i][1];
                check = i;
            }
        }
        
        if(check == -1){
            now++;
            continue;
        }
        
        now += jobs[check][1];
        time.push_back(now-jobs[check][0]);
        jobs.erase(jobs.begin()+check,jobs.begin()+check+1);
    }
    
    for(int i = 0;i < time.size();i++) answer += time[i];
    
    return answer/time.size();
}
