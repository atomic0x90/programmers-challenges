#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int check1 = 0,check2 = 0;
    int num = n;
    while(num){
        if(num % 2 == 1) check1++;
        
        num /= 2;
    }
    for(int i = n+1;;i++){
        check2 = 0;
        num = i;
        int flag = 0;
        while(num){
            if(num % 2 == 1) check2++;
            
            num /= 2;
            
            if(check2 > check1){
                flag = 1;
                break;
            }
        }
        if(flag == 0 && check1 == check2){
            answer = i;
            break;
        }
    }
    return answer;
}
