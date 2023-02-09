#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    for(int i = 0;i < babbling.size();i++){
        string s = babbling[i];
        while(s != ""){
            if(s[0] == 'a'){
                if(s.size() < 3) break;
                if(s[1] == 'y' && s[2] == 'a') s = s.substr(3,s.size());
                else break;
            }
            else if(s[0] == 'y'){
                if(s.size() < 2) break;
                if(s[1] == 'e') s = s.substr(2,s.size());
                else break;
            }
            else if(s[0] == 'w'){
                if(s.size() < 3) break;
                if(s[1] == 'o' && s[2] == 'o') s = s.substr(3,s.size());
                else break;
            }
            else if(s[0] == 'm'){
                if(s.size() < 2) break;
                if(s[1] == 'a') s = s.substr(2,s.size());
                else break;
            }
            else break;
        }
        if(s.size() == 0) answer++;
    }
    return answer;
}
