#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    for(int i = 0;i < babbling.size();i++){
        string s = babbling[i];
        int check = -1;
        while(s != ""){
            if(s[0] == 'a'){
                if(s.size() < 3) break;
                if(s[1] == 'y' && s[2] == 'a' && check != 0) s = s.substr(3,s.size());
                else break;
                
                check = 0;
            }
            else if(s[0] == 'y'){
                if(s.size() < 2) break;
                if(s[1] == 'e' && check != 1) s = s.substr(2,s.size());
                else break;
                
                check = 1;
            }
            else if(s[0] == 'w'){
                if(s.size() < 3) break;
                if(s[1] == 'o' && s[2] == 'o' && check != 2) s = s.substr(3,s.size());
                else break;
                
                check = 2;
            }
            else if(s[0] == 'm'){
                if(s.size() < 2) break;
                if(s[1] == 'a' && check != 3) s = s.substr(2,s.size());
                else break;
                
                check = 3;
            }
            else break;
        }
        if(s.size() == 0) answer++;
    }
    return answer;
}
