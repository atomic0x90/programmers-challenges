#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int sum = brown + yellow;
    int result;
    for(int i = 1;i < sum;i++){
        result = 0;
        if(sum % i == 0){
            if(i >= sum/i){
                result = (i*2)+((sum/i)-2)*2;
                if(result == brown){
                    answer.push_back(i);
                    answer.push_back(sum/i);
                    break;
                }
            }
        }
    }
    return answer;
}
