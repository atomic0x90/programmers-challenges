#include <string>
#include <vector>

using namespace std;

vector<string> solution(string my_str, int n) {
    vector<string> answer;
    for(int i = 0;i < my_str.size();){
        string s = "";
        for(int j = i;j < i+n;j++){
            if(j > my_str.size()-1) break;
            s += my_str[j];
        }
        answer.push_back(s);
        i += n;
    }
    return answer;
}
