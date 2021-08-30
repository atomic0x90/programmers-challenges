#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(string s) {
    int answer = 0;
    
    for(int i = 0;i < s.size();i++){
        stack<char> cstack;
        int flag = 0;
        for(int j = 0;j < s.size();j++){
            if(s[j] == '(') cstack.push(s[j]);
            else if(s[j] == '{') cstack.push(s[j]);
            else if(s[j] == '[') cstack.push(s[j]);
            else{
                if(cstack.empty()){
                    flag = 1;
                    break;
                }
                else{
                    if(cstack.top() == '(' && s[j] == ')') cstack.pop();
                    else if(cstack.top() == '{' && s[j] == '}') cstack.pop();
                    else if(cstack.top() == '[' && s[j] == ']') cstack.pop();
                    else{
                        flag = 1;
                        break;
                    }
                }
            }
        }
        if(cstack.empty() && flag == 0) answer++;
        
        char c = s[0];
        s.erase(s.begin(),s.begin()+1);
        s += c;
    }
    
    return answer;
}
