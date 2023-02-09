#include <string>
#include <vector>
#include <stack>

using namespace std;

string algo(string s){
    if(s == "") return "";
    stack <char> stack;
    string u,v,ts = "";
    int check = 0;
    
    for(int i = 0;i < s.size();i++){
        s[i] == '(' ? check++ : check--;
        u += s[i];
        if(check == 0){
            for(int j = i+1;j < s.size();j++) v += s[j];
            break;
        }
    }
    for(int i = 0;i < u.size();i++){
        if(u[i] == '(') stack.push(u[i]);
        else{
            if(stack.empty()){
                //4
                ts = "(" + algo(v) + ")";
                u.erase(u.begin(),u.begin()+1);
                u.erase(u.end()-1,u.end());
                for(int j = 0;j < u.size();j++){
                    if(u[j] == '(') u[j] = ')';
                    else u[j] = '(';
                }
                ts += u;
                return ts;
            }
            else stack.pop();
        }
    }
    
    return u + algo(v);
}

string solution(string p) {
    string answer = "";
    answer = algo(p);
    return answer;
}
