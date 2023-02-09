#include <iostream>
#include<string>
#include <stack>
using namespace std;

int solution(string s)
{
    int check;
    stack<char> s1;
    stack<char> s2;
    for(int i = 0;i < s.size();i++) s1.push(s[i]);
    
    while(!s1.empty()){
        check = 0;
        for(int i = 0;i < s1.size();i++){
            if(s2.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            else{
                if(s2.top() == s1.top()){
                    s1.pop();
                    s2.pop();
                    check++;
                }
                else{
                    s2.push(s1.top());
                    s1.pop();
                }
            }
        }
        if(check == 0) return 0;
    
        s1 = s2;
    }
    

    return 1;
}
