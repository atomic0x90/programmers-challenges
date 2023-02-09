#include <string>
#include <sstream>
using namespace std;

int solution(string my_string) {
    int answer = 0;
    stringstream ss(my_string);
    string s;
    bool flag;
    
    ss>>s;
    answer = stoi(s);
    
    while(ss>>s){
        if(s == "+") flag = true;
        else if(s == "-") flag = false;
        else{
            if(flag) answer += stoi(s);
            else answer -= stoi(s);
        }
    }
    return answer;
}
