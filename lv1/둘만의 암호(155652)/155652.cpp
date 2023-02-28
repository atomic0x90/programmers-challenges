#include <string>
#include <algorithm>
using namespace std;

string solution(string s, string skip, int index) {
    for(int i = 0;i < s.size();i++){
        char tmp = s[i];
        int ind = index;
        while(ind){
            if(tmp != 'z') tmp++;
            else tmp = 'a';
            if(find(skip.begin(),skip.end(),tmp) == skip.end()) ind--;
        }
        s[i] = tmp;
    }
    return s;
}
