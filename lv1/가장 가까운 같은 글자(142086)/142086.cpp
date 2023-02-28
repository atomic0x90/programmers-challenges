#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> sIndex(26,-1);
    vector<int> answer(s.size(),-1);
    for(int i = 0;i < s.size();i++){
        if(sIndex[s[i]-'a'] == -1) sIndex[s[i]-'a'] = i;
        else{
            answer[i] = i - sIndex[s[i]-'a'];
            sIndex[s[i]-'a'] = i;
        }
    }
    return answer;
}
