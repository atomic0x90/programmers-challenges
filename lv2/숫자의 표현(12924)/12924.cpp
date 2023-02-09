#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int sum,f,t;
    for(int i = 1;i < n;i++){
        sum = 0;
        f = 1;
        t = i+1;
        for(int j = 1;j < i+1;j++) sum += j;
        
        while(true){
            if(sum > n) break;
            else if(sum == n){
                answer++;
                break;
            }
            sum = sum - (f++) + (t++);
        }
    }
    
    return answer;
}
