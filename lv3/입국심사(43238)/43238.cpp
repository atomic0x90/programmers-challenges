#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    int m = *max_element(times.begin(),times.end());
    long long start = 1;
    long long end = (long long)m*(long long)n;
    
    while(start <= end){
        long long num = 0;
        long long mid = (start+end)/2;
        for(int i = 0;i < times.size();i++) num += mid/times[i];
        
        if(num >= n){
            end = mid-1;
            answer = mid;
        }
        else start = mid+1;
    }
    
    return answer;
}
