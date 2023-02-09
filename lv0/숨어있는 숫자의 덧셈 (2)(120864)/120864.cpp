#include <string>

using namespace std;

int solution(string my_string) {
    int answer = 0;
    for(int i = 0;i < my_string.size();i++){
        int num = 0;
        while(isdigit(my_string[i])){
            num = num*10 + my_string[i]-'0';
            i++;
        }
        answer += num;
    }
    return answer;
}
