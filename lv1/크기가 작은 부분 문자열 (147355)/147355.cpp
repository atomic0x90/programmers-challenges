#include <string>
#include <algorithm>
using namespace std;

int solution(string t, string p) {
    int answer = 0;
    for(int i = 0;i < t.size()-p.size()+1;i++){
        string s = "";
        
        for(int j = i;j < i+p.size();j++) s += t[j];
        
        if(stol(p) >= stol(s)) answer++;
    }
    return answer;
}
