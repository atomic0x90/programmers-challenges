#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

long long solution(string expression) {
    long long answer = 0;
    vector <string> pri = {"+","-","*"};
    vector <string> v;
    vector <string> vt;
    vector <string> tmp;
    string s = "";
    
    for(int i = 0;i < expression.size();i++){
        if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*'){
            v.push_back(s);
            s = "";
            if(expression[i] == '+') v.push_back("+");
            else if(expression[i] == '-') v.push_back("-");
            else if(expression[i] == '*') v.push_back("*");
        }
        else s += expression[i];
    }
    v.push_back(s);
    sort(pri.begin(),pri.end());
    
    do{
        vt = v;
        
        for(int i = 0;i < pri.size();i++){
            tmp.clear();
            for(int j = 0;j < vt.size();j++){
                if(tmp.empty()){
                    tmp.push_back(vt[j]);
                    continue;
                }
                
                if(tmp.back() == pri[i]){
                    long long a,b,c;
                    tmp.pop_back();
                    a = stoll(tmp.back());
                    tmp.pop_back();
                    b = stoll(vt[j]);
                    if(pri[i] == "+") c = a+b;
                    else if(pri[i] == "-") c = a-b;
                    else if(pri[i] == "*") c = a*b;
                    tmp.push_back(to_string(c));
                }
                else tmp.push_back(vt[j]);
            }
            
            if(tmp.size() == 1){
                if(answer < llabs(stoll(tmp[0]))) answer = llabs(stoll(tmp[0]));
                break;
            }
            vt = tmp;
        }
    }while(next_permutation(pri.begin(),pri.end()));
    
    
    
    return answer;
}
