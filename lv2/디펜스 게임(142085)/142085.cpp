#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int sum = 0;
    
    priority_queue <int> pq;
    
    for(int i = 0;i < enemy.size();i++){
        if(sum + enemy[i] <= n){
            sum += enemy[i];
            pq.push(enemy[i]);
        }
        else{
            if(!pq.empty()){
                if(k == 0) return i;
                if(pq.top() > enemy[i]){
                    sum -= pq.top();
                    sum += enemy[i];
                    pq.pop();
                    pq.push(enemy[i]);
                    k--;
                }
                else k--;
            }
            else{
                if(k != 0) k--;
                else return i;
            }
            if(sum > n) return i;
        }
    }
}
