#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    int high,low;
    if(n > m){
        high = n;
        low = m;
    }
    else{
        high = m;
        low = n;
    }
    
    int r;
    while(low != 0){
        r = high%low;
        high = low;
        low = r;
    }
    answer.push_back(high);
    answer.push_back((n*m)/high);
    
    return answer;
}
