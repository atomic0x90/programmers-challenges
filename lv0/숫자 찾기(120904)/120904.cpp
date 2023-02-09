#include <string>

using namespace std;

int solution(int num, int k) {
    int answer = -1;
    string s = to_string(num);
    for(int i = 0;i < s.size();i++){
        if(s[i] == to_string(k)[0]){
            answer = i+1;
            break;
        }
    }
    return answer;
}
