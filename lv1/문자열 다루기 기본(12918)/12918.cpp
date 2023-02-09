#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    if(s.size() != 4 && s.size() != 6) return false;
    bool answer = true;
    for(int i = 0; i < s.size();i++){
        if(!(s[i] - '0' >= 0 && s[i] - '0' <= 9)) answer = false;
    }
    return answer;
}
