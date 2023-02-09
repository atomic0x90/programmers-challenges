#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    for(int i = 0;i < s.size();i++){
        for(int j = 1;j <= n;j++){
            if(s[i]-'0' >= 0 && s[i]-'0' <= 9){
                if(s[i]-'0' == 9) s[i] = '0';
                else s[i] += 1;
            }
            else if(s[i] == ' ') break;
            else{
                if(s[i] == 'z') s[i] = 'a';
                else if(s[i] == 'Z') s[i] = 'A';
                else s[i] += 1;
            }
        }
    }
    return s;
}
