#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    vector<long long> value;
    long long lk = (long long)k;
    
    while(true){
        value.push_back(lk);
        if(lk == 1) break;
        if(lk & 1) lk = (3*lk)+1;
        else lk /= 2;
    }
    
    long long n = value.size()-1;
    
    for(int i = 0;i < ranges.size();i++){
        if(ranges[i][0] > n + ranges[i][1]) answer.push_back(-1);
        else{
            double sum = 0;
            int end = (ranges[i][1] > 0 ? ranges[i][1] : n + ranges[i][1]);
            for(int j = ranges[i][0];j < end;j++){
                long long a,b;
                a = value[j];
                b = value[j+1];
                if(a > b) swap(a,b);
                
                sum += a + (b-a)/2.0;
            }
            answer.push_back(sum);
        }
    }
    
    return answer;
}
