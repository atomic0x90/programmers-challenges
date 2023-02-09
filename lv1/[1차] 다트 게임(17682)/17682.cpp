#include <string>
#include <cmath>

using namespace std;

int score[3];

int solution(string dartResult) {
    int answer = 0;
    int check = 0;
    for(int i = 0;i < dartResult.size();i++){
        if(dartResult[i] - '0' >= 0 && dartResult[i] - '0' <= 9){
            if(dartResult[i] - '0' == 1 && dartResult[i+1] - '0' == 0){
                score[check] = 10;
                i++;
            }
            else score[check] = dartResult[i] - '0';
            
            check++;
        }
        else if(dartResult[i] == 'S') score[check-1] = pow(score[check-1],1);
        else if(dartResult[i] == 'D') score[check-1] = pow(score[check-1],2);
        else if(dartResult[i] == 'T') score[check-1] = pow(score[check-1],3);
        else if(dartResult[i] == '*'){
            score[check-1] *= 2;
            if(check-2 >= 0)
                score[check-2] *= 2;
        }
        else if(dartResult[i] == '#') score[check-1] *= -1;
    }    
    
    answer = score[0]+score[1]+score[2];
    
    return answer;
}
