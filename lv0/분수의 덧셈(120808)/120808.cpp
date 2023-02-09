#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int numer1, int denom1, int numer2, int denom2) {
    vector<int> answer;
    if(denom1 != denom2){
        numer1 *= denom2;
        numer2 *= denom1;
        denom1 *= denom2;
        denom2 *= denom1;
    }
    answer.push_back(numer1+numer2);
    answer.push_back(denom1);
    for(int i = 2;i <= answer[1];){
        if(answer[0]%i == 0 && answer[1]%i == 0){
            answer[0] /= i;
            answer[1] /= i;
            i = 2;
        }
        else i++;
    }
    return answer;
}
