#include <cmath>

using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    long long llr1 = (long long)r1;
    long long llr2 = (long long)r2;
    
    for(long long i = 1;i <= r2;i++){
        long long t1;
        if(llr1 >= i) t1 = ceil(sqrt(pow(llr1,2)-pow(i,2)));
        else t1 = 0;
        long long t2 = sqrt(pow(llr2,2)-pow(i,2));
        
        answer += t2-t1+1;
    }
    answer *= 4;
    
    return answer;
}
