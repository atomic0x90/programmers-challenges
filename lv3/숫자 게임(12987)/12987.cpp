#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    int tmp = B.size();
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    for(int i = 0;i < tmp;i++){
        if(A.size() == 0) break;
        
        if(B.back() <= A.back()) A.pop_back();
        else{
            answer++;
            A.pop_back();
            B.pop_back();    
        }
    }
    
    return answer;
}
