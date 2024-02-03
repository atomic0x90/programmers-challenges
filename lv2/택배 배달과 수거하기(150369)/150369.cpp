#include <string>
#include <vector>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    long long allDel = 0;
    long long allPick = 0;
    long long delBack = 0;
    long long pickBack = 0;
    
    for(int i = 0;i < n;i++){
        allDel += deliveries[i];
        allPick += pickups[i];
        if(deliveries[i] != 0) delBack = i;
        if(pickups[i] != 0) pickBack = i;
    }
    
    while(allDel != 0 || allPick != 0){
        long long num = 0;
        long long where = 0;
        
        if(allDel >= cap) num = cap;
        else num = allDel;
        
        allDel -= num;
        
        if(num != 0){
            //deliveries
            for(long long i = delBack;i >= 0;i--){
                if(num == 0) break;
                if(deliveries[i] == 0) continue;

                where = i+1;
                delBack = i;
                
                if(deliveries[i] > num){
                    deliveries[i] -= num;
                    num = 0;
                }
                else if(deliveries[i] == num){
                    deliveries[i] = 0;
                    num = 0;
                }
                else if(deliveries[i] < num){
                    num -= deliveries[i];
                    deliveries[i] = 0;
                    long long j = i-1;
                    while(num){
                        if(deliveries[j] == 0) j--;
                        else{
                            deliveries[j]--;
                            num--;
                        }
                    }
                }
                
                answer += (where)*2;           }
        }//if(num != 0)
        
        if(allPick >= cap) num = cap;
        else num = allPick;
        
        allPick -= num;
        
        if(num != 0){
            //pickups
            for(long long i = pickBack;i >= 0;i--){
                if(num == 0) break;
                if(pickups[i] == 0) continue;
                
                pickBack = i;
                
                if(pickups[i] > num){
                    pickups[i] -= num;
                    num = 0;
                }
                else if(pickups[i] == num){
                    pickups[i] = 0;
                    num = 0;
                }
                else if(pickups[i] < num){
                    num -= pickups[i];
                    pickups[i] = 0;
                    
                    long long j = i-1;
                    while(num){
                        if(pickups[j] == 0) j--;
                        else{
                            pickups[j]--;
                            num--;
                        }
                    }
                }
                if(where < i+1) answer += (i+1-where)*2;
            }
        }//if(num != 0)
    }
    return answer;
}
