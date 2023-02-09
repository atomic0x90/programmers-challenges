#include <vector>

using namespace std;

vector<int> solution(int num, int total) {
    vector<int> answer(num,0);
    
    int middle = total/num;
    if(num%2 == 0){
        for(int i = 0;i < answer.size();i++)
            answer[i] = middle - ((num/2)-i) + 1;
    }
    else{
        for(int i = 0;i < answer.size();i++)
            answer[i] = middle - ((num/2)-i);
    }
    return answer;
}
