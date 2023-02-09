#include <iostream>

using namespace std;
int solution(int n){
    int answer = 0;
    while(true){
        if(n == 0) break;
        
        answer += n%10;
        n = n/10;
    }

    return answer;
}
