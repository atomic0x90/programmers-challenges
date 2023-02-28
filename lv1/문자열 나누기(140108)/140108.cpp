#include <string>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    while(s.size() > 1){
        char x = s[0];
        int check = 1;
        
        for(int i = 1;i < s.size();i++){
            if(x != s[i]) check--;
            else check++;
            
            if(check == 0){
                if(i < s.size()-1) s = s.substr(i+1);
                else s = "";
                
                break;
            }
        }
        answer++;
        if(check != 0) break;
    }
    
    return s.size() == 1 ? answer+1 : answer;
}
