#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    long long tnum = num;
    int check = 0;
    if(tnum == 1) return 0;
    
    while(answer != 500){
        if(tnum%2 == 0) tnum /= 2;
        else tnum = (tnum * 3) + 1;
        
        answer++;
        if(tnum == 1){ 
            check = 1;
            break;
        }
    }
    if(check == 0) answer = -1;
    return answer;
}
