#include <string>
#include <vector>

using namespace std;

int findMaxDivisor(long long n){
    int result = 1;
    for(long long i = 2;i*i <= n;i++){
        if(n%i == 0){
            result = i;
            if(n/i <= 10000000){
                result = n/i;
                break;
            }
        }
    }
    return result;
}

vector<int> solution(long long begin, long long end) {
    vector<int> answer;
    
    for(long long i = begin;i <= end;i++){
        if(i == 1) answer.push_back(0);
        else answer.push_back(findMaxDivisor(i));
    }
    return answer;
}
