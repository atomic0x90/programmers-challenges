#include <string>
#include <vector>
using namespace std;

vector<int> v(26,0);

string solution(string s) {
    string answer = "";
    for(int i = 0;i < s.size();i++)
        v[s[i]-'a']++;
    
    for(int i = 0;i < v.size();i++)
        if(v[i] == 1) answer += 'a'+i;
    
    return answer;
}
