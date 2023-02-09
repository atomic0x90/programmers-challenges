#include <string>
#include <vector>
#include <stack>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    string rem = "";
    stack<char> s;
    for(int i = 0;i < number.size();i++){
        if(k == 0){
            rem += number[i];
            continue;
        }
        if(s.empty()) s.push(number[i]);
        else{
            if(s.top() < number[i]){
                while(!s.empty() && s.top() < number[i] && k != 0){
                    s.pop();
                    k--;
                }
            }
            s.push(number[i]);
        }
    }
    if(k == 0){
        while(!s.empty()){
            answer = s.top() + answer;
            s.pop();
        }
        answer += rem;
    }
    else{
        while(!s.empty()){
            if(k != 0){
                s.pop();
                k--;
            }
            else{
                answer = s.top() + answer;
                s.pop();
            }
        }
    }
    return answer;
}
