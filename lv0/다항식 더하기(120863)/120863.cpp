#include <string>
#include <sstream>

using namespace std;

string solution(string polynomial) {
    string answer = "";
    int value = 0;
    int valueX = 0;
    stringstream ss(polynomial);
    string s;
    while(ss >> s){
        if(s[0] == '+') continue;
        if(s.size() == 1){
            if(s[0] == 'x') valueX++;
            else value += stoi(s);
        }
        else{
            if(s.back() == 'x'){
                s.pop_back();
                valueX += stoi(s);
            }
            else value += stoi(s);
        }
    }
    if(valueX > 1) answer = to_string(valueX)+"x";
    else if(valueX == 1) answer = "x";
    
    if(value != 0){
        if(answer != "") answer += " + "+to_string(value);
        else answer = to_string(value);
    }
    return answer;
}
