#include <string>

using namespace std;

int solution(string A, string B) {
    int answer = 0;
    for(;answer < A.size();answer++){
        if(A == B) break;
        A = A.back()+A;
        A.pop_back();
    }
    return answer == A.size() ? -1 : answer;
}
