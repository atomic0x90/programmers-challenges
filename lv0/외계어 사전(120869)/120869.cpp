#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<string> spell, vector<string> dic) {
    for(int i = 0;i < dic.size();i++){
        bool check = true;
        for(int j = 0;j < spell.size();j++){
            string s = dic[i];
            if(find(s.begin(),s.end(),spell[j][0]) == s.end()){
                check = false;
                break;
            }
        }
        if(check) return 1;
    }
    return 2;
}
