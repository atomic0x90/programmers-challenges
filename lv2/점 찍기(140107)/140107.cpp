#include <cmath>
#include <iostream>
using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    
    for(int i = 0;i <= d;i+=k){
        double j = sqrt(pow(d,2) - pow(i,2));
        
        int n = j;//최대 값 저장
        
        while(n%k != 0) n--;
        
        answer += (n/k)+1;
        
    }
    
    return answer;
}
