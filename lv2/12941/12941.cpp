#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B){
    int answer = 0;
    sort(A.begin(),A.end());
    sort(B.begin(),B.end(),greater<int>());
    while(A.size()){
        int a = A.back();
        int b = B.back();
        
        answer += a*b;

        A.pop_back();
        B.pop_back();
    }
    
    return answer;
}
