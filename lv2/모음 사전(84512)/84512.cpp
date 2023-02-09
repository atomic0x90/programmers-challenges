#include <string>
#include <vector>

using namespace std;

bool flag = false;
int answer = 1;
string s;
string tmp = "AEIOU";

void algo(string word){
    if(flag) return;
    if(s == word){
        flag = true;
        return;
    }
    if(s.size() > 5) return;
    
    answer++;
    
    for(int i = 0;i < 5;i++){
        s += tmp[i];
        algo(word);
        s.pop_back();
    }
}

int solution(string word) {
    for(int i = 0;i < 5;i++){
        s = tmp[i];
        algo(word);
    }
    
    return answer;
}
