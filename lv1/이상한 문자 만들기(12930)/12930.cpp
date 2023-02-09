#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    int check = 0;
    for(int i = 0;i < s.size();i++){
        if(s[i] == ' '){
            check = i+1;
            continue;
        }
        if((check-i)%2==0) s[i] = toupper(s[i]);
        else s[i] = tolower(s[i]);
    }
    
    return s;
}
