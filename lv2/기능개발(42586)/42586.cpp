#include <string>
#include <vector>
#include <deque>
#include <utility>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    deque <pair<int,int> > q;
    vector<int> answer;
    int check;
    for(int i = 0;i < progresses.size();i++)
        q.push_back(make_pair(progresses[i],speeds[i]));
    
    while(!q.empty()){
        check = 0;
        for(int i = 0;i < q.size();i++){
            if(q[i].first < 100) q[i].first += q[i].second;
        }
        
        while(!q.empty()){
            if(q.front().first >= 100){
                q.pop_front();
                check++;
            }
            else break;
        }
        if(check != 0) answer.push_back(check);
        check = 0;
    }
    return answer;
}
