#include <string>
#include <vector>
#include <sstream>
using namespace std;

string solution(string letter) {
    string answer = "";
    vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    stringstream ss(letter);
    while(ss){
        string s;
        ss >> s;
        for(int i = 0;i < morse.size();i++){
            if(s == morse[i]){
                answer += 'a'+i;
                break;
            }
        }
    }
    return answer;
}
