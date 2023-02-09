#include <string>
#include <vector>
#include <deque>
#include <utility>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int nowWeight = 0;
    int num = truck_weights.size();
    int check = 0;
    deque<pair<int,int> > q;    //truck_weights, bridge_length
    deque<int> tw;
    
    for(int i = 0;i < truck_weights.size();i++) tw.push_back(truck_weights[i]);
    
    while(check != num){
        if(q.empty()){
            nowWeight += tw.front();
            q.push_back(make_pair(tw.front(),bridge_length));
            tw.pop_front();
        }
        else{
            for(int i = 0;i < q.size();i++) q[i].second--;
            
            if(q.front().second == 0){
                nowWeight -= q.front().first;
                q.pop_front();
                check++;
            }   
            if(!tw.empty()){
                if(nowWeight + tw.front() <= weight){
                    nowWeight += tw.front();
                    q.push_back(make_pair(tw.front(),bridge_length));
                    tw.pop_front();
                }
            }
        }
        
        answer++;
    }
    
    return answer;
}
