#include <math.h>
using namespace std;

int solution(int number, int limit, int power) {
    int answer = 1;
    for(int i = 2;i <= number;i++){
        int check = 0;        
        
        for(int j = 1;j < double(sqrt(i));j++){
            if(i%j == 0) check += 2;
        }
        if((int)sqrt(i)*(int)sqrt(i) == i) check++;

        
        answer += check > limit ? power : check;
    }
    
    return answer;
}
