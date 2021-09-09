#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int rmv = 0;
    int turn = 0;
    while(s != "1"){
        int check = 0;
        int remainder = 0;
        
        for(int i = 0;i < s.size();i++){
            if(s[i] == '0') check++;
        }
        
        rmv += check;
        
        remainder = s.size() - check;
        
        s = "";
        
        while(remainder != 0){
            s = to_string(remainder%2) + s;
            remainder /= 2;
        }
        
        turn++;
    }
    answer.push_back(turn);
    answer.push_back(rmv);
    return answer;
}
