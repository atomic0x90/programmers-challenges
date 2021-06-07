#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int now[31];
    for(int i = 0;i < n;i++)
        now[i] = 1;
    
    for(int i = 0;i < lost.size();i++)
        now[lost[i]-1] = 0;
    
    for(int i = 0;i < reserve.size();i++)
        now[reserve[i]-1]++;
    
    for(int i = 0;i < n-1;i++){
        if(now[i] == 1) continue;
        else if(now[i] == 2){
            if(now[i+1] == 0){
                now[i]--;
                now[i+1]++;
            }
            else if(now[i-1] == 0){
                now[i-1]++;
                now[i]--;
            }
        }
        else if(now[i] == 0){
            if(now[i+1] == 2){
                now[i]++;
                now[i+1]--;
            }
            else if(now[i-1] == 2){
                now[i]++;
                now[i-1]--;
            }
        }
    }
    
    for(int i = 0;i < n;i++){
        if(now[i] != 0)
            answer++;
    }
    
    return answer;
}
